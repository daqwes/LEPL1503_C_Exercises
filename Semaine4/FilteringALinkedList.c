

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>






if (head == NULL )return NULL ;
struct node *new = malloc(sizeof(*head)) ;
memcpy(new,head , sizeof(*head)) ;
if(head -> next!= NULL) new-> next = pair_filter(head->next->next) ;
return new;