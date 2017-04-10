#ifndef _DOUBLY_LINKED_LIST_H_
#define _DOUBLY_LINKED_LIST_H_

typedef struct node {
  int value;
  struct node *previous;
  struct node *next;
}t_node;

typedef struct {
  t_node *first;
  t_node *last;
}t_list;

t_list *create_list();
t_node *create_node();
void insert_at_head(int value, t_list *list);
void insert_before_pivot(t_node *node, t_node *pivot, t_list *list);
void populate_list(int length, t_list *list);
void free_list(t_list *list);
void print(t_list *list);

#endif
