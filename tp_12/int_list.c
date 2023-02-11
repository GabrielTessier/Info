
#include "int_list.h"

node_t* create_node(int value) {
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->head = value;
    node->tail = NULL;
    return node;
}

int_list_t create_empty_list() {
    int_list_t list = {.node = create_node(0)};
    return list;
}

void add(int_list_t list, int value) {
    if (list.node->tail == NULL) {
        list.node->tail = create_node(list.node->head);
        list.node->head = value;
    } else {
        node_t* second = list.node->tail;
        list.node->tail = create_node(list.node->head);
        list.node->head = value;
        list.node->tail->tail = second;
    }
}

int head(int_list_t list) {
    if (list.node->tail != NULL) {
        return list.node->head;
    } else {
        return 0;
    }
}

int_list_t tail(int_list_t list) {
    int_list_t result = create_empty_list();
    free(result.node);
    result.node = list.node->tail;
    return result;
}

void print_int_list(int_list_t list) {
    if (list.node->tail == NULL) {
        printf("[]\n");
    } else {
        printf("[");
        node_t* node = list.node;
        while (node->tail->tail != NULL) {
            printf("%d, ", node->head);
            node = node->tail;
        }
        printf("%d]\n", node->head);
    }
}

void free_list(int_list_t list) {
    if (list.node->tail != NULL) {
        int_list_t tail_list = tail(list);
        if (tail_list.node != NULL) {
            free_list(tail_list);
        }
    }
    free(list.node);
}

void remove_head(int_list_t list) {
    if (list.node->tail != NULL) {
        list.node->head = list.node->tail->head;
        node_t* t = list.node->tail;
        list.node->tail = t->tail;
        free(t);
    }
}

int length(int_list_t list) {
    int l = 0;
    node_t* node = list.node;
    while (node->tail != NULL) {
        l++;
        node = node->tail;
    }
    return l;
}

int_list_t copy_reverse(int_list_t list) {
    int_list_t reverse = create_empty_list();
    node_t* node = list.node;
    while (node->tail != NULL) {
        add(reverse, node->head);
        node = node->tail;
    }
    return reverse;
}

/*
// Pas optimisée
int_list_t copy_2(int_list_t list) {
    int_list_t reverse = copy_reverse(list);
    int_list_t copy_list = copy_reverse(reverse);
    free_list(reverse);
    return copy_list;
}
*/

int_list_t copy(int_list_t list) {
    if (list.node->tail == NULL) {
        return create_empty_list();
    } else {
        int_list_t t = copy(tail(list));
        add(t, head(list));
        return t;
    }
}

bool list_equal(int_list_t list1, int_list_t list2) {
    node_t* node1 = list1.node;
    node_t* node2 = list2.node;
    while (node1->head == node2->head && node1->tail != NULL && node2->tail != NULL) {
        node1 = node1->tail;
        node2 = node2->tail;
    }
    return node1->tail == NULL && node2->tail == NULL;
}

int_list_t cat(int_list_t list1, int_list_t list2) {
    int_list_t concat = copy(list1);
    int_list_t reverse = copy_reverse(list2);
    node_t* reverse_node = reverse.node;
    while (reverse_node->tail != NULL) {
        add(concat, reverse_node->head);
        reverse_node = reverse_node->tail;
    }
    free_list(reverse);
    return concat;
}

void insert(int_list_t list, int value) {
    node_t* node = list.node;
    node_t* nodep = NULL;
    while (node->head < value && node->tail != NULL) {
        nodep = node;
        node = node->tail;
    }
    if (node->tail != NULL) {
        if (nodep != NULL) {
            node_t* node_to_insert = create_node(value);
            nodep->tail = node_to_insert;
            node_to_insert->tail = node;
        } else {
            add(list, value);
        }
    } else {
        node->head = value;
        node->tail = create_node(0);
    }
}

int_list_t insertion_sort_list(int_list_t list) {
    int_list_t sort_list = copy_reverse(list);
    int len = length(sort_list);
    node_t* nodeI = sort_list.node;
    for (int i=0; i<len; i++) {
        node_t* node_min = nodeI;
        node_t* nodeJ = nodeI->tail;
        for (int j=i+1; j<len; j++) {
            if (nodeJ->head < node_min->head) {
                node_min = nodeJ;
            }
            nodeJ = nodeJ->tail;
        }

        int v = node_min->head;
        node_min->head = nodeI->head;
        nodeI->head = v;

        nodeI = nodeI->tail;
    }
    return sort_list;
}