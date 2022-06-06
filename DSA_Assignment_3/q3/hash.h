#ifndef __HASH_H
#define __HASH_H
#include <stdio.h>
#include <stdbool.h>


struct item{
    int key;
    int frequency;
    struct item* next;
};

struct Bucket{
    struct item* items;
};

struct HashTable{
    int a,b,countBucket;
    struct Bucket* buckets;
};

struct HashTable* init_hash_table(int a,int b, int countBucket);
struct HashTable* insert(struct HashTable* T, int key);
bool search(struct HashTable* T,int key);
struct HashTable* Delete(struct HashTable* T, int key);
void print_table(struct HashTable* T);
struct item* CreateNode(int key);

#endif