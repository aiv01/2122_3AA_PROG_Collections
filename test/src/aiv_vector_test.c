#define CLOVE_SUITE_NAME VectorTest
#include "clove-experimental.h"
#include "aiv_vector.h"

CLOVE_TEST(CreateVector) {

    aiv_vector_t *vector = aiv_vector_new();
    CLOVE_NOT_NULL(vector);
    aiv_vector_free(vector);
}

CLOVE_TEST(CheckIfVectorIsEmptyAfterCreation) {

    aiv_vector_t *vector = aiv_vector_new();
    CLOVE_IS_TRUE(aiv_vector_is_empty(vector));
    aiv_vector_free(vector);
}

CLOVE_TEST(AppendOneElement) {

    aiv_vector_t *vector = aiv_vector_new();
    int a = 5;
    aiv_vector_append(vector, &a);
    CLOVE_IS_FALSE(aiv_vector_is_empty(vector));
    CLOVE_PTR_EQ(&a, *vector->items);
    
    aiv_vector_free(vector);
}

CLOVE_TEST(AppendTwoElements){

    aiv_vector_t *vector = aiv_vector_new();
    int a = 5;
    int b = 15;
    aiv_vector_append(vector, &a);
    aiv_vector_append(vector, &b);

    CLOVE_PTR_EQ(&a, vector->items[0]);
    CLOVE_PTR_EQ(&b, vector->items[1]);

    aiv_vector_free(vector);
}

/*
#include "clove.h"

CLOVE_TEST(FirstManualTest) {
    CLOVE_PASS();
}

CLOVE_SUITE(ManualSuite) {
    CLOVE_SUITE_TESTS(FirstManualTest);
}
*/