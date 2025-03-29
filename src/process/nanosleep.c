#include <internal/syscall.h>
#include <stdlib.h>
#include <time.h>

int nanosleep(const struct timespec *rqtp, struct timespec *rmtp) {
    int ns = syscall(__NR_nanosleep, rqtp, rmtp);
    return ns;
}
