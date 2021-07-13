// Iain Muir, iam9ez
// April 9th, 2020
// linkedlist.c

#include <stdio.h>
#include <stdlib.h>

int main() {
  struct LinkedList {
    struct ListNode* head;
    struct ListNode* tail;
    struct ListNode* current;
  };

  struct ListNode {
    struct ListNode* next;
    struct ListNode* prev;
    int value;
  };

  int n;
  printf("Enter how many values to input: ");
  scanf("%d", &n);

  struct LinkedList *list = (struct LinkedList *) malloc(sizeof(struct LinkedList));
  list->head = NULL;
  list->tail = NULL;
  
  for (int i = 1; i <= n; i++) {
    struct ListNode *node = (struct ListNode *) malloc(sizeof(struct ListNode));
    printf("Enter value %.0d: ", i);
    scanf("%d", &(node->value));

    if (i == 1) {
      list->head = node;
      list->current = node;
      list->head->next = NULL;
      list->head->prev = NULL;
    }
    else {
      list->current->next = node;
      node->prev = list->current;
      list->current = node;
      node->next = NULL;       
    }  
  }

  printf("%s\n", "---------------------");
  
  for (int i = 1; i <= n; i++){
    printf("%d\n", list->current->value);
    if (list->current == list->head) {
      free(list->current);
      break;
    }  
    list->current = list->current->prev;
    free(list->current->next);
    // list->current->next = NULL;
  }  

  free(list);
  
  return 0;
}
