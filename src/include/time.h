#ifndef _TIME_H
#define _TIME_H

#include <stddef.h>  // for NULL

// Define time_t as an integer type to hold time in seconds
typedef long time_t;

// Define the structure for holding time in seconds and nanoseconds
struct timespec {
    time_t tv_sec;    // Seconds
    long tv_nsec;     // Nanoseconds
};

// Get the current time in seconds since the Epoch (usually 1970-01-01 00:00:00 UTC)
time_t time(time_t *tloc);

// Pause execution for a specified time (seconds + nanoseconds)
int nanosleep(const struct timespec *req, struct timespec *rem);

#endif  // _TIME_H
