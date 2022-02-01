#define CLOVE_SUITE_NAME VectorBadMemoryTest
#include "clove-experimental.h"
#include "aiv_vector.h"
#include "test_utils.h"


static void* bad_alloc(size_t value) {
    return NULL;
}

static void* bad_realloc(void* block, size_t value) {
    return NULL;
}

CLOVE_TEST(CreateVectorWithFailingMalloc) {
    aiv_vector_allocator_t bad_allocator = {bad_alloc, bad_realloc};
    aiv_vector_t *vector = aiv_vector_new_with_alloc(bad_allocator);
    CLOVE_NULL(vector);
}

CLOVE_TEST(CreateVectorWithFailingRealloc) {
    aiv_vector_allocator_t half_bad_allocator = {malloc, bad_realloc};
    aiv_vector_t *vector = aiv_vector_new_with_alloc(half_bad_allocator);
    
    void** items_ptr_before_append = vector->items;

    int value = 1;
    aiv_vector_append(vector, &value);

    void** items_ptr_after_append = vector->items;
    //CLOVE_NOT_NULL(vector->items); //da verificare
    CLOVE_PTR_EQ(items_ptr_before_append, items_ptr_after_append);
    CLOVE_INT_EQ(0, vector->count);
}

