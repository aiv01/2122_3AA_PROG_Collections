#pragma once
#include <stdbool.h>

typedef struct aiv_vector
{
    void *value;
}aiv_vector_t;


/*
 * create a new vector
 * @return an instance of aiv_vector_t or NULL in case of error
*/
aiv_vector_t *aiv_vector_new();


/*
 * destroy a allocated vector structure
 * @param vector vector to free
*/
void aiv_vector_free(aiv_vector_t *vector);

/*
 * check if the given vector is empty
 * @param vector the vector to be checked
*/
bool aiv_vector_is_empty(aiv_vector_t *vector);

/*
 * append a value to the vector
 *
 * @param vector The vector to append the new value
 * @param value The pointer of the value to append 
 */
void aiv_vector_append(aiv_vector_t *vector, void *value);