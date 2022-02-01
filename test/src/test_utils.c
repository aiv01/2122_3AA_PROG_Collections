#include "test_utils.h"
#include <stdlib.h>
#include <stdio.h>
int test_type = 1;

void* __aiv_malloc(size_t v) {
    if (test_type == 0) {
         puts("AIV MALLOC BAD");
        return NULL;
    } else {
        puts("AIV MALLOC GOOD");
        return malloc(v);
    }
}