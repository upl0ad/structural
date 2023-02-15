#include <stdlib.h>

// A dynamic array of integers.
typedef struct Array
{
  int len;
  int* underlying;
} Array;

Array new_array(int len)
{
  Array arr;
  arr.underlying = malloc(sizeof(int) * len);
  arr.len = len;
  return arr;
}

void delete_array(Array arr)
{
  free(arr.underlying);
}
