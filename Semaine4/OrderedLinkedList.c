// 88% - NOT FINISHED 
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





   if (cmp('a','b') <0){
    
    node_t *current; 
    node_t *newNode = malloc(sizeof(node_t)) ;
    if (newNode == NULL){
        return -1 ;
    }
    newNode -> val = val ;
    /* Special case for the head end */
    if (*head == NULL || (*head)->val > newNode->val) 
    { 
        newNode->next = *head; 
        *head = newNode; 
        return 0 ;
    } 
    else if ((*head)->val == newNode->val){
        return 0 ;
    }
    else
    { 
        /* Locate the node before the point of insertion */
        current = *head; 
        while (current->next!=NULL && 
               current->next->val < newNode->val) 
        {if(current->val != val){
            current = current->next; 
        }else {
            return 0 ;
        } }
        newNode->next = current->next; 
        current->next = newNode; 
        return 0 ;
    } 
}
 else {
     node_t *current; 
    node_t *newNode = malloc(sizeof(node_t)) ;
    if (newNode == NULL){
        return -1 ;
    }
    newNode -> val = val ;
    /* Special case for the head end */
    if (*head == NULL || (*head)->val < newNode->val) 
    { 
        newNode->next = *head; 
        *head = newNode; 
        return 0 ;
    } 
     else if ((*head)->val == newNode->val){
        return 0 ;
    }
    else
    { 
        /* Locate the node before the point of insertion */
        current = *head; 
        while (current->next!=NULL && 
               current->next->val > newNode->val) 
        {if(current->val != val){
            current = current->next; 
        }else {
            return 0 ;
        } }
        newNode->next = current->next; 
        current->next = newNode; 
        return 0 ;
    } 
 }
