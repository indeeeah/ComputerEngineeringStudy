#include <stdio.h>

int arr[] = {4, 5, 5, 7, 4, 6, 8, 6};
int count = sizeof(arr) / sizeof(int);

void removeAt(int index) {
    for (int i = index ; i < count ; i++) {
        arr[i] = arr[i + 1];
    }
    count--;
}

void show() {
    for (int i = 0 ; i < count ; i++) {
        printf("%d ", arr[i]);
    }
}

int main(void) {
    removeAt(5);
    show();

    return 0;
}