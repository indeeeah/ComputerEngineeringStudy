## IPC 기법과 커널모드
* pipe, message queue는 모두 커널 공간의 메모리를 사용한다.
* `ipcs` 명령어로 현재 커널 공간에 생성되어있는 메세지 큐, 공유메모리, semaphore를 볼 수 있다.
* `msgctl(msgid, IPC_RMID, 0);` : 해당 메세지 큐를 커널 영역에서 삭제한다.

---
## 공유메모리(shared memory)
* 노골적으로 kernel space에 메모리 공간을 만들고 해당 공간을 변수처럼 쓰는 방식
* message queue 처럼 FIFO 방식이 아니라, 해당 메모리 주소를 마치 변수처럼 접근하는 방식
* 공유메모리 key를 가지고 여러 프로세스가 접근 가능
---
## 공유 메모리 코드 예제
1. 공유 메모리 생성
```C
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// key : 임의 숫자 또는 ftok 함수로 생성한 키 값
// size : 공유 메모리 크기
// shmflg : 공유 메모리 속성
// 리턴 값 : 공유 메모리 식별자 리턴
int shmget(key_t key, size_t size, int shmflg);

// 예
shmid = shmget((key_t)1234, SIZE, IPC_CREAT|0666)
```
2. 공유 메모리 연결
```C
#include <sys/types.h>
#include <sys/shm.h>

// shmid: shmget 함수로 생성한 공유 메모리 식별자
// shmaddr : 공유 메모리 연결 주소(보통 (char *)NULL으로 설정하면 알아서 적절한 주소로 연결)
// shmflg: 공유 메모리의 읽기/쓰기 권한 (0이면 읽기/쓰기 가능, SHM_RDONLY면 읽기만 가능)
// 리턴 값: 성공시 연결된 공유 메모리의 시작 주소를 리턴
void *shmat(int shmid, const void *shmaddr, int shmflg);

// 예
shmaddr = (char *)shmat(shmid, (char *)NULL, 0)
```
3. 공유 메모리 해제
```C
#include <sys/types.h>
#include <sys/shm.h>

int shmdt(char *shmaddr);
```
4. 공유 메모리에서 읽기
```C
printf("%s\n", (char *)shmaddr)
```
5. 공유 메모리에 쓰기
```C
strcpy((char *)shmaddr, "Linux Programming")
```
---
* shmctl()
```C
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// shmid: shmget 함수로 생성한 공유 메모리 식별자
// cmd : 수행할 제어 기능 (예: IPC_RMID - shmid로 지정한 공유 메모리 제거)
// buf : 제어 기능에 사용되는 공유 메모리 구조체의 구조

int shmctl(int shmid, int cmd, struct shmid_ds *buf);

// 예
shmctl(shmid, IPC_RMID, (struct shmid_ds *)NULL);
```
```C
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
        int shmid, pid;
        char *shmaddr_parent, *shmaddr_child;
        shmid = shmget((key_t)1234, 10, IPC_CREAT|0644);
        if(shmid == -1) {
                perror("shmget error\n");
                exit(1);
        }
        pid = fork();
        if(pid > 0) {   // parent process
                wait(0);        // wait for child process exit
                shmaddr_parent = (char *)shmat(shmid, (char *)NULL, 0);
                printf("%s\n", shmaddr_parent);
                shmdt((char *)shmaddr_parent);
        }
        else {  // child process
                shmaddr_child = (char *)shmat(shmid, (char *)NULL, 0);
                strcpy((char *)shmaddr_child, "Hello Parent!");
                shmdt((char *)shmaddr_child);
                exit(0);
        }
        shmctl(shmid, IPC_RMID, (struct shmid_ds *)NULL);
        return 0;
}
```
