#include <stdio.h>
#include "array.c"

int main(void)
{
  array* arr = new_array(10);
  for (int i = 0; i < 10; i++)
    arr[i] = i;

  for (int i = 0; i < 10; i++)
    printf("%d\n", arr[i]);

  printf("%d", len(arr));
  return 0;
}
