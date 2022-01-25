#define CLOVE_SUITE_NAME VectorTest
#include "clove-experimental.h"
#include "aiv_vector.h"

 aiv_vector_t *vector;

CLOVE_SUITE_SETUP() {
    vector = aiv_vector_new();
}

CLOVE_SUITE_TEARDOWN() {
    aiv_vector_free(vector);
}

CLOVE_TEST(CreateVector) {
    CLOVE_NOT_NULL(vector);
}

CLOVE_TEST(CheckIfVectorIsEmptyAfterCreation) {
    CLOVE_IS_TRUE(aiv_vector_is_empty(vector));
}

CLOVE_TEST(AppendOneElement) {
    int a = 5;
    aiv_vector_append(vector, &a);

    CLOVE_IS_FALSE(aiv_vector_is_empty(vector));
    CLOVE_PTR_EQ(&a, *vector->items);
}

CLOVE_TEST(AppendTwoElements){
    int a = 5;
    int b = 15;
    aiv_vector_append(vector, &a);
    aiv_vector_append(vector, &b);

    CLOVE_PTR_EQ(&a, vector->items[0]);
    CLOVE_PTR_EQ(&b, vector->items[1]);
}

CLOVE_TEST(GetFirstElement){
    int a = 5;
    aiv_vector_append(vector, &a);

    CLOVE_PTR_EQ(&a, aiv_vector_at(vector, 0));
}

CLOVE_TEST(GetElementOutOfRange){
    int a = 5;
    aiv_vector_append(vector, &a);

    CLOVE_NULL(aiv_vector_at(vector, -1));
    CLOVE_NULL(aiv_vector_at(vector, 2));
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