#include "syscall.h"
#define SIZE 10
int dummyArray[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int main() {
    int i;
    for (i = 0; i < SIZE; i++) {
        PrintInt(dummyArray[i]);
    }
    // return 0;
    Halt();
}