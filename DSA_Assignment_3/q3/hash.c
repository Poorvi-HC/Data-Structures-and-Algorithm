#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long long int delete_count=0;
long long int search_count=0;
long long int insert_count=0;
long long int delete_call=0;
long long int search_call=0;
long long int insert_call=0;

struct HashTable* init_hash_table(int a,int b,int countBucket)
{
    struct HashTable* H;
    H = (struct HashTable*) malloc(sizeof(struct HashTable));
    H->a = a;
    H->b = b;
    H->countBucket = countBucket;
    H->buckets = (struct Bucket*) malloc(countBucket * sizeof(struct Bucket));
    for (int i = 0;i<countBucket;i++)
    {
        H->buckets[i].items = (struct item*) malloc(sizeof(struct item));
        H->buckets[i].items->key = 0;
        H->buckets[i].items->frequency = 0;
        H->buckets[i].items->next = NULL;
    }
    return H;
}

struct item* CreateNode(int key)
{
    struct item* node = (struct item*) malloc(sizeof(struct item));
    node->frequency = 0;
    node->key = key;
    node->next = NULL;
    return node;
}

struct HashTable* insert(struct HashTable* T, int key)
{
    insert_call++;
    int a = T->a;
    int b = T->b;
    int countBucket = T->countBucket;

    int index = (a*key + b)%countBucket;
    struct item* node = CreateNode(key);

    if (T->buckets[index].items->next == NULL)
    {
        insert_count++;
        T->buckets[index].items->next = node;
        node->frequency = 1;
        return T;
    }
    else
    {
        struct item* temp;
        temp = T->buckets[index].items->next;
        if (temp->key == node->key)
        {
            insert_count++;
            temp->frequency += 1;
            return T;
        }
        while(temp->next != NULL)
        {    
            insert_count++;
            if (temp->key == node->key)
            {
                temp->frequency += 1;
                return T;
            }
            temp = temp->next;
        }
        if (temp->key == node->key)
        {
            insert_count++;
            temp->frequency += 1;
            return T;
        }
        temp->next= node;
        temp->next->frequency = 1;
    }
    return T;
}

/*//insert at beginning
struct HashTable* insert(struct HashTable* T, int key)
{
    int a = T->a;
    int b = T->b;
    int countBucket = T->countBucket;

    int index = (a*key + b)%countBucket;
    struct item* node = CreateNode(key);

    if (T->buckets[index].items->next == NULL)
    {
        T->buckets[index].items->next = node;
        node->frequency = 1;
        return T;
    }
    else
    {
        struct item* temp;
        temp = T->buckets[index].items->next;
        if (temp->key == node->key)
        {
            temp->frequency += 1;
            return T;
        }
        while(temp->next != NULL)
        {    
            if (temp->key == node->key)
            {
                temp->frequency += 1;
                return T;
            }
            temp = temp->next;
        }
        if (temp->key == node->key)
        {
            temp->frequency += 1;
            return T;
        }
        node->next = T->buckets[index].items->next;
        T->buckets[index].items->next = node;
        node->frequency = 1;
    }
    return T;
}*/

struct HashTable* Delete(struct HashTable* T, int key)
{
    delete_call++;
    int a = T->a;
    int b = T->b;
    int countBucket = T->countBucket;

    int index = (a*key + b)%countBucket;

    if (T->buckets[index].items == NULL)
    {
        delete_count++;
        return T;
    }   
    else
    {
        struct item* temp;
        temp = T->buckets[index].items;
        while(temp->next != NULL)
        {
            delete_count++;
            if (temp->next->key == key)
            {  
                struct item* remove;
                remove = temp->next;
                if (remove->frequency > 1)
                {
                    remove->frequency -= 1;
                    return T; 
                }
                else if (temp->next->next != NULL)
                    temp->next = temp->next->next;
                else
                    temp->next = NULL;
                free(remove);
                return T;
            }
            temp = temp->next;
        }
    }
}

void print_table(struct HashTable* T)
{
    int countBucket = T->countBucket;
    int flag = 0;
    for (int i = 0;i<countBucket;i++)
    {
        if (T->buckets[i].items->next != NULL)
            flag = 1;
    }
    if (flag == 0)
    {
        printf("NULL\n");
        return;
    }
    struct item* temp = NULL;
    for (int i = 0;i<countBucket;i++)
    {
        int flager = 0;
        temp = T->buckets[i].items->next;
        while(temp != NULL)
        {
            if (temp->frequency != 0)
            {
                printf("%d %d ",temp->key,temp->frequency);
                flager = 1;
            }
            temp = temp->next;
        }
        if (flager == 1)
            printf("\n");
    }
    free(temp);
}

bool search(struct HashTable* T,int key)
{
    search_call++;
    int a = T->a;
    int b = T->b;
    int countBucket = T->countBucket;

    int idx = (a*key+b)%countBucket;
    struct item* temp = T->buckets[idx].items;
    while(temp != NULL)
    {
        search_count++;
        if (temp->key == key)
            return true;
    
        temp = temp->next;
    }
    free(temp);
    return false;
}

