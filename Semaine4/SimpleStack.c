
{
    if (head == NULL || *head == NULL ) {
        return 1; 
    }
    strncpy(result,(*head)->name, strlen((*head)->name)+1) ;
    free((*head)->name);  
    struct node *temp = *head; 
    *head = (*head)->next;   
    free(temp);
    return 0;
    }





{
    if (head == NULL ){
        return 1 ;
    }
    else {
    struct node node  ;
    node.name = malloc(sizeof(char) * (strlen(value ) +1));
    if(node.name == NULL ) { 
    return 1 ;
    }
        
    strcpy(node.name , value) ;
    
    struct node* stackNode = (struct node*)malloc(sizeof(node));
    *stackNode = node ;
     
    if (stackNode == NULL){
        return 1;
    }
    if (*head == NULL ){
        stackNode -> next = NULL ;
        *head = stackNode ; 
    }
    else {
        stackNode-> next = *head ; 
        *head = stackNode ; 
    }
    return 0 ;
    }
}