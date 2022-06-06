#include <stdio.h>
#include <stdlib.h>
#include "my_dll.h"
#include "node.h"
#include <string.h>
#include <assert.h>

int main()
{   
    printf("Create your own double link list:-\n");
    printf("List of commands are as follows:-\n");
    printf("to insert a peice of data at the end of list- insert <data>\n");
    printf("to insert data at position p- insert_at <data> <position>\n");
    printf("to delete node at position p- delete <position>\n");
    printf("to search for an element x- find <data>\n");
    printf("To delete all the odd indexes data- prune\n");
    printf("To print the list- print\n");
    printf("To print list in reverse- print_reverse\n");
    printf("To be informed of the size of the list- get_size\n");
    printf("To Quit- quit:-\n");
    printf("*********************\n");

    list* dll;
    dll = (list*) malloc(sizeof(list));
    assert(dll != NULL);

    node* head;
    head = generate_node();

    dll->root = head;
    dll->size = 0;

    int c,pos,retval;

    char str[12];
    //if you use string pointer here, you need to use malloc
    while(strcmp(str,"quit") != 0)
    {
        printf("Enter command:-\n");
        scanf("%s", str);

        if (strcmp("insert",str) == 0)
        {
            scanf("%d", &c);
            insert(dll, c);
        }
        else if (strcmp("insert_at",str) == 0)
        {
            scanf("%d %d", &c, &pos);
            insert_at(dll, c,pos);
        }
        else if (strcmp("delete",str) == 0)
        {
            scanf("%d",&pos);
            delete(dll,pos);
        }   
        else if (strcmp("find",str) == 0)
        {
            scanf("%d", &c);
            retval = find(dll,c);
            printf("position of the given data is (zero indexed):- %d\n", retval);
        }
        else if (strcmp("prune",str) == 0)
        {
            prune(dll);
        }
        else if (strcmp("print",str) == 0)
        {
            print(dll);
        }   
        else if (strcmp("print_reverse",str) == 0)
        {
            print_reverse(dll);
        }
        else if (strcmp("get_size",str) == 0)
        {
            retval = get_size(dll);
            printf("size of the linked list is:- %d\n",retval);
        }

        printf("*********************\n");
    }

    return 0;
}