#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[100]; // 숫자가 길수도 있기 때문에 문자열로 초기화
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

void push(Stack *stack, char *data) {
    Node *node = (Node*)malloc(sizeof(Node));
    strcpy(node->data, data);   // 각 노드는 데이터를 포함하고 있기 때문에 매개변수로 들어온 데이터 즉 문자열을 노드 안에 담을수있게
    node->next = stack->top;    // 현재 스택의 탑을 노드의 다음이 가르키게하고
    stack->top = node;  // 스택의 탑을 노드가 될 수 있게
}

char* getTop(Stack *stack) {
    Node *top = stack->top; // 최상단 노드를 반환할 수 있게
    return top->data;
}

char* pop(Stack *stack) {
    if (stack->top == NULL) {
        printf("스택 언더플로우가 발생했습니다.\n");
        return NULL;
    }
    Node *node = stack->top;
    char *data = (char*)malloc(sizeof(char) * 100);
    strcpy(data, node->data);
    stack->top = node->next;
    free(node);
    return data;
}

int getPriority(char *i) {
    if (!strcmp(i, "(")) return 0;  // 우선순위가 가장 낮음
    if (!strcmp(i, "+") || !strcmp(i, "-")) return 1;
    if (!strcmp(i, "*") || !strcmp(i, "/")) return 2;
    return 3;
}



// 후위표기법
// s는 37 * 5라고 들어왔을 때 
// "37", "*", "5" 라고 각 문자열로 본다는 뜻
// size는 각 들어오는 문자열의 사이즈
char* transition(Stack *stack, char **s, int size) {
    char res[1000] = "";
    for (int i = 0 ; i < size ; i++) {
        // 문자열이 연산자라면 
        if (!strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "*") || !strcmp(s[i], "/")) {
            // 자기보다 우선순위가 높은 것을 뽑은 다음에
            while (stack->top != NULL && getPriority(getTop(stack)) >= getPriority(s[i])) {
                // 스택에 넣는다.
                strcat(res, pop(stack));
                // 띄어쓰기
                // 3 + 5가 들어오면 3 5 + 이렇게 띄어쓰기를 해준다
                strcat(res, " ");
            }
            push(stack, s[i]);
        } else if (!strcmp(s[i], "(")) {
            push(stack, s[i]);
        } else if (!strcmp(s[i], ")")) {
            while (strcmp(getTop(stack), "(")) {
                // ")"이 나왔다면 "("가 나올때까지 스택에 넣어준다.
                strcat(res, pop(stack));
                strcat(res, " ");
            }
            pop(stack);
        } else {
            // 일반 숫자인 경우 바로 출력
            strcat(res, s[i]);
            strcat(res, " ");
        }
    }
    while (stack->top != NULL) {
        // 스택에 남아있는 문자가 있다면 다 꺼내줌
        strcat(res, pop(stack));
        strcat(res, " ");
    }
    return res;
}

void calculate(Stack *stack, char **s, int size) {
    int x, y, z;
    for (int i = 0 ; i < size ; i++) {
        if (!strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "*") || !strcmp(s[i], "/")) {
            x = atoi(pop(stack));
            y = atoi(pop(stack));
            // y가 더 먼저 들어간 문자이기 때문에 y가 먼저 들어가야 한다.
            if (!strcmp(s[i], "+")) {
                z = y + x;
            }
            if (!strcmp(s[i], "-")) {
                z = y - x;
            }
            if (!strcmp(s[i], "*")) {
                z = y * x;
            }
            if (!strcmp(s[i], "/")) {
                z = y / x;
            }
            char buffer[100];
            // 계산된 숫자의형태를 문자로 넣겠다는 것
            sprintf(buffer, "%d", z);
            // 그것을 다시 스택에 넣겠다는 것
            push(stack, buffer);
        } else {
            push(stack, s[i]);
        }
    }
    printf("%s\n", pop(stack));
}

int main(void) {
    Stack stack;
    stack.top = NULL;
    char a[100] = "( ( 3 + 4 ) * 5 ) - 5 * 7 * 5 - 5 * 10";  // 계산 수식
    int size = 1;   // 각 문자열의 개수
    for (int i = 0 ; i < strlen(a) ; i++) {
        if (a[i] == ' ') {
            size++;
        }
    }
    char *ptr = strtok(a, " "); // 띄어쓰기를 이용하여 토큰으로 만들어줌
    char **input = (char**)malloc(sizeof(char*) * size);    // 후위표기법에 넣으려는 입력값
    for (int i = 0 ; i < size ; i++) {
        input[i] = (char*)malloc(sizeof(char) * 100);   // 각 문자열은 최대 100까지
    }
    for (int i = 0 ; i < size ; i++) {
        strcpy(input[i], ptr);  // 토큰으로 분리된 각 문자열 확인
        ptr = strtok(NULL, " ");    // 그 다음 토큰 확인
    }
    // 띄어쓰기로 이루어진 각 문자열 배열 형태로 인풋에 담기게됨
///////////////////////////////////////////////////////////////////////////

    char b[1000] = "";
    strcpy(b, transition(&stack, input, size));
    printf("후위 표기법 : %s\n", b);
    size = 1;
    for (int i = 0 ; i < strlen(b) - 1 ; i++) {  // 마지막은 항상 공백이 들어가므로 1을 빼기
        if (b[i] == ' ') {
            size++;
        }
    }
    char *ptr2 = strtok(b, " ");
    for (int i = 0 ; i < size ; i++) {
        strcpy(input[i], ptr2);
        ptr2 = strtok(NULL, " ");
    }
    calculate(&stack, input, size);

    return 0;
}