#include "aiv_vector.h"
#include <stdlib.h>

aiv_vector_t *aiv_vector_new()
{
    aiv_vector_t *vector = (aiv_vector_t *)malloc(sizeof(aiv_vector_t));
    if (vector == NULL)
    {
        return NULL;
    }
    vector->value = NULL;
    return vector;
}

void aiv_vector_free(aiv_vector_t *vector)
{
    free(vector);
}

bool aiv_vector_is_empty(aiv_vector_t *vector)
{
    return vector->value == NULL;
}

void aiv_vector_append(aiv_vector_t *vector, void *value)
{
    vector->value = value;
}