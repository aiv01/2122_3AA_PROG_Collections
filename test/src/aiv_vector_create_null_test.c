#define CLOVE_SUITE_NAME VectorCreateNullTest
#include "clove-experimental.h"
#include "aiv_vector.h"
#include "test_utils.h"

/*
void* __aiv_malloc(size_t v) {
    puts("AIV MALLOC BAD");
    return NULL;
}
*/

CLOVE_TEST(CreateVectorWithFailingMalloc) {
    test_type = 0;
    aiv_vector_t *vector = aiv_vector_new();
    CLOVE_NULL(vector);
}
