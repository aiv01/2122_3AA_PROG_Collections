#include "aiv_vector.h"
#include <stdlib.h>

aiv_vector_t *aiv_vector_new()
{
    return (aiv_vector_t*)malloc(sizeof(aiv_vector_t));
}

void aiv_vector_free(aiv_vector_t *vector)
{
    free(vector);
}