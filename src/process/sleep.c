#include <internal/syscall.h>
#include <stdlib.h>
#include <time.h>

unsigned int sleep(unsigned int seconds) {
    struct timespec req = {seconds, 0};
    nanosleep(&req, NULL);
    return 0;
}
