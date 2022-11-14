## 다양한 IPC 기법
* IPC : InterProcess Communication
1. file 사용
2. Message Queue
3. Shared Memory
4. Pipe
5. Signal
6. Semaphore
7. Socket

## 파이프
* pipe(파이프)
    + 기본 파이프는 단방향 통신
    + fork()로 자식 프로세스 만들었을 때 부모와 자식간의 통신
    + 꼭 부모 자식간이어야 한다.
```C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MSGSIZE 255

char* msg = "Hello Child Process!";
int main(){
    char buf[255];
    int fd[2], pid, nbytes; // fd[0]과 fd[1]을 가짐
    if (pipe(fd) < 0)   // pipe(fd)로 파이프 생성
        exit(1);
    pid = fork();   // 이 함수 실행 다음 코드부터 부모/자식 프로세스로 나뉘어짐
    if (pid > 0) {  // 부모 프로세스에는 자식 프로세스 pid 값이 들어감
        printf("parent PID:%d, child PID:%d\n", getpid(), pid);
        write(fd[1], msg, MSGSIZE); // fd[1]에 씁니다.
        exit(0);
    }
    else {  // 자식 프로세스에는 pid 값이 0이어야 함
        printf("child PID:%d\n", getpid());
        nbytes = read(fd[0], buf, MSGSIZE);  // fd[0]으로 읽음
        printf("%d %s\n", nbytes, buf);
        exit(0);
    }
    return 0;
}
```
* 결과물
```
ubuntu@ip-172-31-3-92:~/programming$ ./pipe
parent PID:30898, child PID:30899
ubuntu@ip-172-31-3-92:~/programming$ child PID:30899
255 Hello Child Process!
```

---
## 메세지 큐 (message queue)
* 큐니까 기본은 FIFO
```C
msqid = msgget(key, msgflg) // key는 1234, msgflg는 옵션
```
* msgget(정수값, 메세지큐 옵션) 이라는 함수로 메세지 큐를 하나 만들어야 함
* msgflg 설정
    + IPC_CREAT : 새로운 키면 식별자를 새로 생성, IPC_CREAT|접근권한
    + 예: IPC_CREAT|0644 -> rw-r--r--
        - 권한을 줄 수 있다.
```C
msgsnd(msqid, &sbuf, buf_length, IPC_NOWAIT)
```
* msgsnd(메시지큐 아이디, 데이터, 데이터사이즈, 메세지큐 옵션) 
* msgflg 설정 : 블록모드 (0) - 데이터 읽을때까지 코드 멈춤 / 비블록 모드(IPD_NOWAIT) - 읽지않더라도 다음 코드 실행
### 메세지큐 전송 프로그램 일부 코드 예
```C
msqid = msgget(1234, IPC_CREAT|0644)
msgsnd(msqid, &sbuf, buf_length, IPC_NOWAIT)
```

## 메세지큐 코드 예제
```C
ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg)
msgrcv(msqid, &rbuf, MSGSZ, 1, 0)   // msgrcv 예
```
* msgtyp 설정: 0이면 첫번째 메세지, 양수이면 타입이 일치하는 첫번째 메세지
* msgflg 설정 : 블록모드(0)/ 비블록모드(IPC_NOWAIT)
### 메시지큐 수신 프로그램 일부 코드 예
```C
msqid = msgget(1234, IPC_CREAT|0644)    // key는 동일하게 1234로 해야 해당 큐의 msgid를 얻을 수 있다.
msgrcv(msqid, &rbuf, MSGSZ, 1, 0)
```
> msgqueuesend.c
```C
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/msg.h>

typedef struct msgbuf {
        long type;
        char text[50];
} MsgBuf;

int main(void) {
        int msgid, len;
        MsgBuf msg;
        key_t key = 1234;
        msgid = msgget(key, IPC_CREAT|0644);
        if(msgid == -1) {
                perror("msgget");
                exit(1);
        }
        msg.type = 1;
        strcpy(msg.text, "Hello Message Queue\n");
        if(msgsnd(msgid, (void *)&msg, 50, IPC_NOWAIT) == -1) {
                perror("msgsnd");
                exit(1);
        }
        return 0;
}
```
> msgqueuercv.c
```C
#include <sys/msg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct msgbuf {
        long type;
        char text[50];
} MsgBuf;

int main(void) {
        MsgBuf msg;
        int msgid, len;
        key_t key = 1234;
        if((msgid = msgget(key, IPC_CREAT|0644)) < 0) {
                perror("msgget");
                exit(1);
        }
        len = msgrcv(msgid, &msg, 50, 0, 0);
        printf("Receive Message is [%d] %s\n", len, msg.text);
        return 0;
}
```
* msgqueuesend만 실행했을 때는 아무것도 출력되지 않는다.
    + 해당 키에 해당하는 메세지 큐는 커널영역에 생성된 상태이다.
* msgqueuercv을 실행하면 메세지를 받은 것을 알 수 있다.

> msgqueuesendrcv.c
```C
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/msg.h>

typedef struct msgbuf {
        long type;
        char text[50];
} MsgBuf;

int main(void) {
        int msgid, len;
        MsgBuf msg;
        key_t key = 1234;
        msgid = msgget(key, IPC_CREAT|0644);
        if(msgid == -1) {
                perror("msgget");
                exit(1);
        }
        msg.type = 1;
        strcpy(msg.text, "Hello Message Queue\n");
        if(msgsnd(msgid, (void *)&msg, 50, IPC_NOWAIT) == -1) {
                perror("msgsnd");
                exit(1);
        }
        len = msgrcv(msgid, &msg, 50, 0, 0);
        printf("Received Message is '%s' [%d]\n", msg.text, len);
        return 0;
}
```
* 실행하자마자 데이터를 넣고 받는것까지 하는 코드

---
* ftok() : 키 생성을 위한 함수
    + path 경로명의 inode 값과 숫자값(id)를 기반으로 키 생성
    + 경로 삭제 후 재생성시 inode 값이 달라지므로, 이전과는 다른 키값이 리턴
```C
#include <sys/ipc.h>

key_t ftok(const char *path, int id);

// 예
key = ftok("keyfile", 1);   // 디렉토리 또는 inode값과 임의 숫자값
id = msgget(key, IPC_CREAT|0640);
```