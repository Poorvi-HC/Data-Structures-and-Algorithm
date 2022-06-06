#ifndef QUEUE_H
#define QUEUE_H
#include "tree.h"

typedef struct Node_Queue
{
    struct Node_Tree *address;
    int l_r;
    struct Node_Queue *next;
} QNode;

typedef struct Queue
{
    struct Node_Queue *head;
    struct Node_Queue *tail;
    int size;
} queue;

int push(struct Queue*, struct Node_Tree*, int l_r);
int pop(struct Queue*);
queue* CreateQueue();
int isEmpty(queue *Q);
QNode* front(struct Queue*);
QNode* back(struct Queue*);

#endif