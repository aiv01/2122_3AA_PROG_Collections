#include "aiv_vector.h"
#include <stdlib.h>

aiv_vector_t *aiv_vector_new()
{
    aiv_vector_t *vector = (aiv_vector_t *)malloc(sizeof(aiv_vector_t));
    if (vector == NULL)
    {
        return NULL;
    }
    vector->count = 0;
    vector->items = NULL;
    return vector;
}

void aiv_vector_free(aiv_vector_t *vector)
{
    free(vector);
}

bool aiv_vector_is_empty(aiv_vector_t *vector)
{
    return vector->items == NULL;
}

void aiv_vector_append(aiv_vector_t *vector, void *value)
{
    vector->items = realloc(vector->items, sizeof(void*) * (vector->count +1));
    vector->items[vector->count] = value;
    vector->count++;
}

void* aiv_vector_at(aiv_vector_t *vector, int index)
{
    if (index < 0 || index >= vector->count)
    {
        return NULL;
    }
    return vector->items[index];
}