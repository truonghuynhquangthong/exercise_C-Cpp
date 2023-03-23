#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct node
{
  uint8_t data;
  struct node *next;
} node;

void addNode(node *arr, uint8_t data)
{
  node *newNode = (node *)malloc(sizeof(node));
  newNode->data = data;
  newNode->next = NULL;

  if (arr->next == NULL)
  {
    arr->next = newNode;
    return;
  }
  node *p = arr->next;
  while (p->next != NULL)
    p = p->next;
  p->next = newNode;
}

void prin(node *arr)
{
  for (node *p = arr->next; p != NULL; p = p->next)
  {
    printf("%d\n", p->data);
  }
}

int main()
{
  node arr = {0, NULL};
  addNode(&arr, 2);
  addNode(&arr, 17);
  addNode(&arr, 9);
  addNode(&arr, 8);
  prin(&arr);
  return (0);
}