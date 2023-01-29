#define MAXN 20
#include "syscall.h"

int main(void) {
    int fid[MAXN + 5];
    int status;
    int i;
    int retVal;
    char filename[] = "file00.test";
    char msg_create[] = "Failed on creating file00";
    char msg_open[] =   "Failed on opening file00";
    for (i = 0; i < MAXN + 5; i++) {
        filename[5] = (i % 10) + '0';
        filename[4] = (i / 10) + '0';
        retVal = Create(filename);
        if (retVal == -1) {
            msg_create[24] = (i % 10) + '0';
            msg_create[23] = (i / 10) + '0';
            MSG(msg_create);
        }
    }

    for (i = 0; i < MAXN; i++) {
        filename[5] = (i % 10) + '0';
        filename[4] = (i / 10) + '0';
        fid[i] = Open(filename);
        if (fid[i] == -1) {
            msg_open[23] = (i % 10) + '0';
            msg_open[22] = (i / 10) + '0';
            MSG(msg_open);
        }
    }

    retVal = Open("file20.test");
    if (retVal != -1) {
        MSG("Need to error opening file20");
    }

    retVal = Close(fid[0]);
    if (retVal != 1) {
        MSG("Failed on closing 0");
    }

    fid[0] = Open("file20.test");
    if (fid[0] == -1) {
        MSG("Failed on opening file20");
    }

    retVal = Open("FileNotExist");
    if (retVal != -1) {
        MSG("Need to error opening FileNotExist");
    }

    MSG("Passed.");
    Halt();
}
