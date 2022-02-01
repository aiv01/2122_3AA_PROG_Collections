#include "aiv_vector.h"
#include <stdlib.h>
#include "aiv_memory.h"

aiv_vector_t *aiv_vector_new()
{   
    aiv_vector_allocator_t real_allocator;
    real_allocator.malloc_func = malloc;
    real_allocator.realloc_func = realloc;
    return aiv_vector_new_with_alloc(real_allocator);
}

aiv_vector_t* aiv_vector_new_with_alloc(aiv_vector_allocator_t allocator) {
    aiv_vector_t *vector = (aiv_vector_t *)allocator.malloc_func(sizeof(aiv_vector_t));
    if (vector == NULL)
    {
        return NULL;
    }
    vector->count = 0;
    vector->items = NULL;
    vector->allocator = allocator;
    return vector;
}



void aiv_vector_free(aiv_vector_t *vector)
{
    vector->count = 0;
    free(vector->items);
    vector->items = NULL;
    free(vector);    
}

bool aiv_vector_is_empty(aiv_vector_t *vector)
{
    return vector->items == NULL;
}

void aiv_vector_append(aiv_vector_t *vector, void *value)
{   
    //void* new_item = vector->allocator.future_size_will_be(vector->count + 1);
    void* new_item = vector->allocator.realloc_func(vector->items, sizeof(void*) * (vector->count +1));
    if (!new_item)  {
        return;
    }

    vector->items = new_item;
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