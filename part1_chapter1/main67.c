#include <stdio.h>
#include <string.h>

// struct Student {
//     char studentId[10];
//     char name[10];
//     int grade;
//     char major[100];
// } s = {"1111111", "김수민", 4, "패션디자인학과"};    // 전역변수로 사용

// typedef
typedef struct {
    char studentId[10];
    char name[10];
    int grade;
    char major[100];
} Student;

int main(void) {
    // struct Student s;
    // strcpy(s.studentId, "1111111");
    // strcpy(s.name, "김수민");
    // s.grade = 4;
    // strcpy(s.major, "패션디자인학과");

    //typedef
    Student s = {"1111111", "김수민", 4, "패션디자인학과"};
    printf("학번 : %s\n", s.studentId);
    printf("이름 : %s\n", s.name);
    printf("학년 : %d\n", s.grade);
    printf("학과 : %s\n", s.major);

    // 구조체가 포인터 변수로 사용되는 경우 -> malloc이 안되는데 왜 안되는지 모르겠음..
    // Student *s = (Student*)malloc(sizeof(Student));
    // strcpy(s->studentId, "1111111");
    // strcpy(s->name, "김수민");
    // s->grade = 4;
    // strcpy(s->major, "패션디자인학과");
    // printf("학번 : %s\n", s->studentId);
    // printf("이름 : %s\n", s->name);
    // printf("학년 : %d\n", s->grade);
    // printf("학과 : %s\n", s->major);
    return 0;
}
