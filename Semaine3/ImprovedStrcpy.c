{    int i ;
    if (src== NULL) {
        return NULL ; 
    }
    
    char *dest = malloc((strlen(src)+1)*sizeof(char));
    if (dest == NULL) {
        return NULL;
    }
    
    
    for(i = 0;src[i] != '\0';i++){
        dest[i] = src[i];
    }
    dest[i] = '\0';
        

    return dest;
    
}