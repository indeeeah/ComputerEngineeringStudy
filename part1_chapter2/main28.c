#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>   // 무작위 데이터를 5000개 삽입해볼 것임
#define TABLE_SIZE 10007
#define INPUT_SIZE 5000

typedef struct Student {
    int id;
    char name[20];
} Student;

// 해쉬 테이블 초기화
void init(Student** hashTable) {
    for (int i = 0 ; i < TABLE_SIZE ; i++) {
        hashTable[i] = NULL;
    }
}

// 해쉬 테이블의 메모리 반환
void destructor(Student** hashTable) {
    for (int i = 0 ; i < TABLE_SIZE ; i++) {
        if (hashTable[i] != NULL) {
            free(hashTable[i]);
        }
    }
}

// 해시 테이블 내 빈 공간을 선형 탐색으로 찾습니다.
int findEmpty(Student** hashTable, int id) {
    int i = id % TABLE_SIZE;
    while (1) {
        if (hashTable[i % TABLE_SIZE] == NULL) {    // 이미 차있다면
            return i % TABLE_SIZE;
        }
        i++;
    }
}

// 특정한 ID 값에 매칭되는 데이터를 해시 테이블 내에서 찾습니다.
int search(Student** hashTable, int id) {
    int i = id % TABLE_SIZE;
    while (1) {
        if (hashTable[i % TABLE_SIZE] == NULL) {    // 비어있다면
            return -1;
        } else if (hashTable[i % TABLE_SIZE]->id == id) {   // 특정 id값과 일치한다면
            return 1;
        }
        i++;
    }
}

// 특정한 키 인덱스에 데이터를 삽입합니다.
void add(Student** hashTable, Student* input, int key) {
    hashTable[key] = input;
}

// 해시 테이블에서 특정한 키의 데이터를 반환합니다.
Student* getValue(Student** hashTable, int key) {
    return hashTable[key];
}

// 해시 테이블에 존재하는 모든 데이터를 출력합니다.
void show(Student** hashTable) {
    for (int i = 0 ; i < TABLE_SIZE ; i++) {
        if (hashTable[i] != NULL) {
            printf("키 : [%d] 이름 : [%s]\n", i, hashTable[i]->name);
        }
    }
}

int main(void) {
    Student **hashTable;
    hashTable = (Student**) malloc(sizeof(Student) * TABLE_SIZE);
    init(hashTable);

    for (int i = 0 ; i < INPUT_SIZE ; i++) {
        Student* student = (Student*) malloc(sizeof(Student));
        student->id = rand() % 1000000;
        sprintf(student->name, "사람%d", student->id);

        if(search(hashTable, student->id == -1)) {  // 중복되는 ID는 존재하지 않도록 함
            int index = findEmpty(hashTable, student->id);
            add(hashTable, student, index);
        }
    }

    show(hashTable);
    destructor(hashTable);

    return 0;
}