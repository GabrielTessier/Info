
#ifndef INT_LIST_H
#define INT_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node_s
{
    int head;
    struct node_s* tail;
} node_t;

typedef struct int_list_s
{
    node_t* node;
} int_list_t;



node_t* create_node(int value);
int_list_t create_empty_list();
void add(int_list_t list, int value);
int head(int_list_t list);
int_list_t tail(int_list_t list);
void print_int_list(int_list_t list);
void free_list(int_list_t list);
void remove_head(int_list_t list);
int length(int_list_t list);
int_list_t copy_reverse(int_list_t list);
int_list_t copy(int_list_t list);
bool list_equal(int_list_t list1, int_list_t list2);
int_list_t cat(int_list_t list1, int_list_t list2);
void insert(int_list_t list, int value);
int_list_t insertion_sort_list(int_list_t list);


#endif  // INT_LIST_H