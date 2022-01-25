#include "aiv_vector.h"
#include <stdlib.h>

aiv_vector_t *aiv_vector_new()
{
    aiv_vector_t *vector = (aiv_vector_t*)malloc(sizeof(aiv_vector_t));
    return vector;
}

void aiv_vector_free(aiv_vector_t *vector)
{
    free(vector);
}

bool aiv_vector_is_empty(aiv_vector_t *vector)
{
    return true;
}