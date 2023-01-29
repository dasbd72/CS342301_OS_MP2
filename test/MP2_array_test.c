#include "syscall.h"
#define SIZE (3 * 1024 + 624) // Maximum Size
// #define SIZE (3 * 1024 + 625) // MLE
int dummyArray[SIZE];
int main() {
    int i;
    dummyArray[0] = 0;
    for (i = 1; i < SIZE; i++) {
        dummyArray[i] = dummyArray[i - 1] + i;
    }
    PrintInt(sizeof(int) * SIZE);
    PrintInt(dummyArray[SIZE - 1]);
    // return 0;
    Halt();
}