#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = (Node*) malloc(sizeof(Node));
        root->leftChild = root->rightChild = NULL;
        root->data = data;
        return root;
    } else {
        if (root->data > data) {
            root->leftChild = insertNode(root->leftChild, data);
        } else {
            root->rightChild = insertNode(root->rightChild, data);
        }
    }
    return root;
}

Node* searchNode(Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == data) {
        return root;
    } else if (root->data > data) {
        return searchNode(root->leftChild, data);
    } else {
        return searchNode(root->rightChild, data);
    }
}

// 가장 작은 원소를 찾는 함수
Node* findMinNode(Node* root) {
    Node* node = root;
    while (node->leftChild != NULL) {
        node = node->leftChild;
    }
    return node;
}

Node* deleteNode(Node* root, int data) {
    Node* node = NULL;
    if (root == NULL) {
        return NULL;
    }

    if (root->data > data) {
        root->leftChild = deleteNode(root->leftChild, data);
    } else if (root->data < data) {
        root->rightChild = deleteNode(root->rightChild, data);
    } else {
        if (root->leftChild != NULL && root->rightChild != NULL) {
            node = findMinNode(root->rightChild);
            root->data = node->data;
            root->rightChild = deleteNode(root->rightChild, node->data);
        } else {    // 왼쪽자식이나 오른쪽자식이 존재한다면
            node = (root->leftChild != NULL) ? root->leftChild : root->rightChild;
            free(node);
            return node;
        }
    }
    return root;
}

// 전위순회 방식
void preorder(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->leftChild);
    preorder(root->rightChild);
}

int main(void) {
    Node* root = NULL;
    root = insertNode(root, 30);
    root = insertNode(root, 17);
    root = insertNode(root, 48);
    root = insertNode(root, 5);
    root = insertNode(root, 23);
    root = insertNode(root, 37);
    root = insertNode(root, 50);
    root = deleteNode(root, 30);
    preorder(root);
}