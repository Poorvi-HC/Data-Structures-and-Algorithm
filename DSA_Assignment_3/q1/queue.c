#include "queue.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


QNode *CreateQNode(struct Node_Tree *address, int l_r)
{
    QNode *new = (QNode *)malloc(sizeof(QNode));
    new->address = address;
    new->l_r = l_r; //root = (0) left - (-1) right - (1)
    new->next = NULL;
    return new;
}

queue *CreateQueue()
{
    queue *Q = (queue *)malloc(sizeof(queue));
    Q->size = 0;
    Q->head = NULL;
    Q->tail = NULL;
    return Q;
}

int push(queue *Q, struct Node_Tree *address, int l_r)
{
    QNode *new = CreateQNode(address, l_r);
    if (Q->tail == NULL)
    {
        Q->tail = new;
        Q->size += 1;
        Q->head = new;
    }
    else
    {
        Q->tail->next = new;
        Q->tail = new;
        Q->size += 1;
    }
    return 1;
}

int pop(queue *Q)
{
    if (Q->size == 0)
        return 0;

    QNode *temp = Q->head;
    if (Q->size == 1)
    {
        // Q->head = Q->head->next;//
        Q->head = NULL;
        Q->tail = NULL;
        free(temp);
        Q->size -= 1;
    }
    else
    {
        Q->head = Q->head->next;
        free(temp);
        Q->size -= 1;
    }
    return 1;
}

int isEmpty(queue *Q)
{
    if (Q->head == NULL)
        return 1;
    else
        return 0;
}

QNode *front(queue *Q)
{
    return Q->head;
}

QNode *back(queue *Q)
{
    return Q->tail;
}