#include "aiv_memory.h"
#include <stdlib.h>

void* __aiv_malloc(size_t v) {
    return malloc(v);
}