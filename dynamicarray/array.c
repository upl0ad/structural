// a dynamic array is a data structure that
// allows you to "dynamically" manage the space
// it occupies. It is nothing but an array, really.
//
// The thing with C is that it doesnt allow dynamic
// memory allocation, bcs it doesnt have a garbage collector.
// So we are going go implement a "dynamic" array
#include <stdlib.h>

typedef int array;


array* new_array(int n)
{
  array* x = malloc(n * sizeof(array));
}

// TODO: implement len()
/* size_t len(array* arr) { */
/*   return sizeof(arr) / sizeof(arr[0]); */
/* } */

void append(array* arr, int element)
{
  // TODO: implement this
}
