#include <stdio.h>
#include <stdlib.h>

typedef struct  Node {
    int data;   // 실제로는 정수형 데이터만 들어가는 것이 아니라 많은 데이터가 들어간다.
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

Node* initNode(int data, Node* leftChild, Node* rightChild) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->leftChild = leftChild;
    node->rightChild = rightChild;

    return node;
}

// 전위 순회
void preorder(Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->leftChild);
        preorder(root->rightChild);
    }
}

// 중위 순회
void inorder(Node* root) {
    if (root) {
        inorder(root->leftChild);
        printf("%d ", root->data);
        inorder(root->rightChild);
    }
}

// 후위 순회
void postorder(Node* root) {
    if (root) {
        postorder(root->leftChild);
        postorder(root->rightChild);
        printf("%d ", root->data);
    }
}

int main(void) {
    Node* n7 = initNode(50, NULL, NULL);    // 가장 오른쪽 자식 노드
    Node* n6 = initNode(37, NULL, NULL);
    Node* n5 = initNode(23, NULL, NULL);
    Node* n4 = initNode(5, NULL, NULL);
    Node* n3 = initNode(48, n6, n7);    // 자식노드 존재
    Node* n2 = initNode(17, n4, n5);
    Node* n1 = initNode(30, n2, n3);    // root node

    preorder(n1);
    printf("\n");
    inorder(n1);
    printf("\n");
    postorder(n1);

    return 0;
}