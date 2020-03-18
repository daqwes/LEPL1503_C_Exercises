
{
    if (a == b){
        return 0;
    }
    else if (a>b) {
        return 1;
    }
    else {
        return -1;
    }
}





if(*head == NULL){
    node_t *new = malloc(sizeof(node_t));
    if(new == NULL) return -1 ;
    new->val = val;
    new -> next = NULL ;
    *head  = new ;
    return 0 ;
}
if(cmp(val,(*head)->val) <0) {
    node_t *new = malloc(sizeof(node_t)) ;
    if(new== NULL) return -1 ;
    new->val = val ;
    new -> next = *head ;
    *head = new ;
    return 0 ; 
}
node_t *ptr = *head ;
while(ptr->next != NULL){
    if(cmp(val,ptr->val) == 0 ) return 0 ;
    if(cmp(val,ptr->next->val)< 0 ){
        node_t *new = malloc(sizeof(node_t)) ;
        if(new == NULL) return -1 ;
        new->val = val  ;
        new-> next = ptr->next ;
        ptr-> next = new ;
        return 0; 
    }
    ptr = ptr -> next ; 
}
if (cmp(val,ptr->val) == 0) return 0 ;
node_t *new = malloc(sizeof(node_t)) ;
if(new == NULL) return -1 ;
new->val = val ;
new-> next = NULL ;
ptr->next = new ;
return 0 ;
