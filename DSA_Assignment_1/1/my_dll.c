#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "my_dll.h"

// Insert a node containing data x at the end of the linked list
/* the trav nodes generated in each of the functions is used to traverse 
 through the list to a desired location */
// The temp node stores the data removed or added
// the temp is also freed when removed
int insert(list* dll, int data)
{
    node* trav = generate_node();
    trav = dll->root;
    while(trav->next != NULL)
    {
        trav = trav->next;
    }
    node* temp = generate_node();
    temp->data = data;
    temp->prev = trav;
    trav->next = temp;

    dll->size += 1;
    return 1;
}

int insert_at(list* dll, int data,int pos)
{
    if (dll == NULL)
        return -1;
    if (pos > dll->size)
        return -1;
    
    node* trav = generate_node();
    trav = dll->root;
    for (int i = 0;i<pos;i++)
    {
            trav = trav->next;
    }
    
    node* temp = generate_node();
    if(trav->next != NULL && trav != dll->root)
    {
        temp->data = data;
        temp->next = trav->next;
        temp->prev = trav;
        trav->next = temp;
        trav->next->next->prev = temp;

        dll->size += 1;
    }

    else if(trav == dll->root && trav->next != NULL)
    {
        temp->data = data;
        temp->next = trav->next;
        temp->prev = NULL;
        trav->next = temp;
        temp->next->prev = temp;
        dll->size += 1;
    }

    else
    {
        insert(dll,data);
    }
    
    return 1;
}

int delete(list* dll, int pos)
{
    
    if (dll == NULL)
        return -1;
    if (dll->size == 0)
        return -1;
    if (pos > dll->size)
        return -1;
  
    node* trav = generate_node();
    trav = dll->root;
    

    for (int i = 0;i < pos;i++)
    {
        trav = trav->next;
    }

    node* temp = generate_node();
    
    if (trav->next->next != NULL && trav != dll->root)
    {
        temp = trav->next;
        trav->next = temp->next;
        temp->next->prev = trav;
        free(temp);
    }

    else if(trav->next->next != NULL && trav == dll->root)
    {
        temp = trav->next;
        trav->next = temp->next;
        temp->next->prev = NULL;
        free(temp);
    }

    else
    {
        temp = trav->next;
        trav->next = NULL;
        free(temp);
    }

    dll->size -= 1;
    
    return 1;
}


int find(list* dll, int data)
{
    if (dll == NULL)
        return 0;
    if (dll->size == 0)
        return 0;

    node* trav = generate_node();
    trav = dll->root->next;

    for (int i = 0;i < (dll->size);i++)
    {
        if (trav->data == data)
            return i;
        else
            trav = trav->next;
    }
    return -1;
}

int prune(list* dll)
{
    if (dll == NULL)
        return -1;
    if (dll->size == 0)
        return -1;

    for (int i = 1;i<dll->size;i = i + 1)
    {
        delete(dll,i);
    }
    
    return 1;
}

int print(list* dll)
{
    if (dll == NULL)
        return -1;
    if (dll->size == 0)
    {
        printf("NA\n");
        return -1;
    }
    
    node* temp = generate_node();
    temp = dll->root;

    for (int i = 0;i < dll->size;i++)
    {
        temp = temp->next;
        printf("%d ",temp->data);
    }
    printf("\n");
    return 1;
}

int print_reverse(list* dll)
{
    if (dll == NULL)
        return -1;
    if (dll->size == 0)
    {
        printf("NA");
        return -1;
    }
    
    node* temp = generate_node();
    temp = dll->root;

    while(temp->next != NULL)
        temp = temp->next;
    
    for (int i = 0;i<dll->size;i++)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
    return 1;
}

int get_size(list* dll)
{
    return dll->size;
}
