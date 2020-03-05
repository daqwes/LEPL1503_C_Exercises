{ struct node *node = malloc(sizeof(node_t));
 
    if (q->size == 0 ) {
    
    node ->value = val ;
    q->tail = node ;
    q->tail->next = node;
    q->size =1;
    return 0;
}
 else if (q->size == 1){
    
    node -> next = q->tail ;
    node ->value = val ;
    q->tail->next = node ;
    q-> size ++ ;
    return 0;
     
 }
    
    if (node == NULL ){
        return -1;
    }
    node -> next = q->tail->next ;
    node->value = val ;
    q->tail->next = node ;
    q-> size ++ ;
    return 0;
}






{   int value;  
    if (q->size == 1) 
    { 
        value = q->tail->value; 
        free(q->tail); 
        q->tail->next = NULL; 
        q->tail = NULL; 
        q->size = 0 ;
    } 
    else 
    {   int val = q->tail->value;
        node_t *temp = q->tail ;
        while (temp->next != q->tail ){
            temp = temp->next;
        }
        node_t *rem = temp -> next ;
        temp->next = q->tail->next ;
        q->tail = temp;
        free(rem);
        q->size--;
        value = val;
        
        
    } 
  
    return value ; 
} 