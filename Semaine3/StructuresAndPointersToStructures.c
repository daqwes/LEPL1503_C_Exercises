
{
    
    return ptrProd->price ;
}




{
    return prod.price;
}





{
    char *s = malloc((strlen(ptrProd->name)+1)* sizeof(char) );
    if (s== NULL){
        return NULL;
    }
    strcpy(s, ptrProd->name);
    return s;
}





{
    char *s = malloc((strlen(prod.name)+1)* sizeof(char) );
    if (s== NULL){
        return NULL;
    }
    strcpy(s,prod.name);
    return s;
}




{  if (strcmp(ptrProd->name, prod.name) != 0 || ptrProd-> price != prod.price ){
        return 0 ;
    }
 return 1 ;
}