#ifndef __MY_DLL_H
#define __MY_DLL_H

#include "node.h"

//Gives the list which contains the head pointer and the size of the list
typedef struct my_dll{
    node* root;
    int size;
}list;

int insert(list* dll, int data);
int insert_at(list* dll, int data, int pos);
int delete(list* dll, int pos); 
int find(list* dll, int data);
int prune(list* dll);
int print(list* dll);
int print_reverse(list* dll);
int get_size(list* dll);

#endif