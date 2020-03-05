// 28.5% - NOT FINISHED 

{   struct stat file_stat;
    int fd  =  open (filename , O_RDWR | O_CREAT | O_TRUNC) ;
    int a = 0 ;
    if ( fd == -1) {
        return -1 ;
    }
    int size = fstat( fd , &file_stat ) ; 
    if ( size == -1){
        return -1 ; 
    }
    if ( index >= size ){ 
     return -2 ; 
    }
    void *mem  = mmap (NULL, size, PROT_READ, MAP_SHARED, fd, 0) ; 
    int *nbre = mem ; 
    if ( mem == NULL ){
        return -1 ; 
    }
    for ( int i = 0 ; i < size ; i++) {
        a += nbre[i] ;  
    }
    int unmem =  munmap( mem , size ) ; 
    if ( unmem == -1 && mem != NULL){
        return -1;
    }
    int fdc = close( fd) ;
    if ( fdc  == -1){
        return -1 ;
    }
    return a ;
}




{   struct stat file_stat;
    int fd  =  open (filename , O_RDWR | O_CREAT | O_TRUNC) ;
    if ( fd == -1) {
        exit(-1);
    }
    int size = fstat( fd , &file_stat ) ; 
    if ( size == -1){
        exit(-1) ; 
    }
    if ( index >= size ){ 
     exit(-1); 
    }
    void *mem  = mmap (NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0) ; 
    int *nbre = mem ; 
    if ( mem == NULL ){
        exit(-1) ; 
    }
    nbre[index] = value ;   
    
    int unmem =  munmap( mem , size ) ; 
    if ( unmem == -1 && mem != NULL){
        exit(-1);
    }
    int fdc = close( fd) ;
    if ( fdc  == -1){
        exit(-1) ;
    }
}