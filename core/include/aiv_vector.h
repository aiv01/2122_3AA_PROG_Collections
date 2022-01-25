#pragma once

typedef struct aiv_vector
{
    int p;
}aiv_vector_t;



aiv_vector_t *aiv_vector_new();
void aiv_vector_free(aiv_vector_t *vector);