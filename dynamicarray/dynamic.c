#include <stdio.h>
#include <stdlib.h>
#include "array.c"

int main(void)
{
  Array arr = new_array(10);
  for (int i = 0; i < 10; i++)
    arr.underlying[i] = i;

  for (int i = 0; i < 10; i++)
    printf("%d\n", arr.underlying[i]);

  delete_array(arr);

  printf("%d", arr.underlying[9]);

  return 0;
}
