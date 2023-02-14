#include <stdio.h>
#include <stdbool.h>
#include "linked_list.c"

int main(void)
{
  List* list = NewList(0);

  for (int i = 0; i < 10; i++)
  {
    append_node(list, i); // populating likned list
  }

  printf("top content: %d\n", list->top->content);
  printf("root content: %d\n", list->root->content);

  printf("begin iteration over the linked list\n");
  Node* current = list->root;
  while (true)
  {
    printf("%d\n", current->content);

    if (current->next == NULL)
      break;

    current = get_next_node(current);
  }


  return 0;
}
