#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>

int puts(const char* str) {
    int w = write(1, str, strlen(str));
    if (w < 0)
        return -1;
    w = write(1, "\n", 1);
    if (w < 0)
        return -1;
    return 0;
}
