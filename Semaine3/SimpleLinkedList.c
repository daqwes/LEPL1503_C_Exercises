{
    
        node_t *n = malloc(sizeof(node_t));
    if (n==NULL){
        return NULL;
    }
        n->value = value;
        n->next = NULL;
        return n;
    
}





{   if (list == NULL ) {
    return 1;
}
    
    else if (list == NULL){
        init_node(value);
        return 0;
    }
    else {
        node_t *n = malloc(sizeof(node_t));
        if (n == NULL) {
            return 1;
        }
        n->value  = value ;
        n->next = list->first;
        list->first = n;
        (list->size)++ ;
        return 0;
    }
}