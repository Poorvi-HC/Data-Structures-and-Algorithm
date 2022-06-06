#ifndef __NODE_H
#define __NODE_H

// Node is the most basic unit of a linked list
typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
} node;

node* generate_node();

#endif