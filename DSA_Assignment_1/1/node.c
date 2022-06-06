#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "node.h"

//creates a fresh node with properties of header pointer
node* generate_node()
{
    node* head = (node*) malloc(sizeof(node));
    assert(head != NULL);

    head->prev = NULL;
    head->next = NULL;
    head->data = 0;

    return head;
}


