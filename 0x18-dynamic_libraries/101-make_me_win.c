#define _GNU_SOURCE
#include <stdio.h>
#include <time.h>

time_t time(time_t *tloc) {
    if (tloc != NULL)
        *tloc = 0;
    return 0;
}
