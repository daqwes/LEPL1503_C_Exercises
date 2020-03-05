// 75% - NOT FINISHED 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>






{
    if (head == NULL ) {
        return NULL;
    }
    else {
        int i =0 ;
        struct node *curr = malloc(sizeof(struct node));
        if (curr == NULL ){
            return NULL;
        }
        else if(head->next == NULL ){
            return head ; 
        }
        else if(head-> next-> next == NULL ){
            return head ->next ;
        }
        while(curr->next != NULL){
        if(i%2 != 0){
            struct node *temp = malloc(sizeof(struct node ));
            *temp = *head;
            temp->next = NULL;
            curr = curr->next = temp;
            i++;
        }
        curr = curr->next;
        i++;
    }
    
    return curr->next;
    }
}