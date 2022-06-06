#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "hash.h"

int main()
{
    
    int number_of_tests;
    printf("No. of Commands:");
    scanf("%d",&number_of_tests);

    struct HashTable* T;
    T = init_hash_table(1,2,10);//-->hardcoded
    
    for (int i=0;i<number_of_tests;i++)
    {   
        char str[200];
        scanf("%s",str);

        if (strcmp(str,"INSERT") == 0)
        {
            long long int data;
            scanf("%lld",&data);
            T = insert(T,data);
        }
        else if(strcmp(str,"PRINT") == 0)
        {
            print_table(T);
        }
        else if(strcmp(str,"DELETE") == 0)
        {
            long long int data;
            scanf("%lld",&data);
            T = Delete(T,data);
        } 
        else if(strcmp(str,"SEARCH") == 0)
        {
            long long int data;
            scanf("%lld",&data);
            search(T,data);
 //           if (search(T,data))
 //               printf("data found in hash table\n");
  //          else
   //             printf("NA\n");
        }
    }
    return 1;
}
