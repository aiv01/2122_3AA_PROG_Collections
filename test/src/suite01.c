#define CLOVE_SUITE_NAME Suite01
#include "clove-experimental.h"

CLOVE_TEST(FirstTest) {
    CLOVE_PASS();
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