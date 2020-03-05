{for (int i = 0 ; i<10;i++){
    void *ptr = malloc(s) ;
    if (ptr != NULL ){
        return ptr ;
    }
    sleep(5) ;
}
 return NULL ; 
}