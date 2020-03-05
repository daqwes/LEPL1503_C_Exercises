// 37.5% - NOT FINISHED 


{   struct stat file_stat;
    int fd  =  open (filename , O_RDWR | O_CREAT | O_TRUNC) ;
    int a = 0 ;
    if ( fd == -1) {
        return -1 ;
    }
    int size = fstat( fd , &file_stat ) ; 
    if ( size == -1){
        return -5 ; 
    }
    void *mem  = mmap (NULL, size, PROT_READ, MAP_SHARED, fd, 0) ; 
    int *nbre = mem ; 
    if ( mem == NULL ){
        return -3 ; 
    }
    for ( int i = 0 ; i < size ; i++) {
        a += nbre[i] ;  
    }
    int unmem =  munmap( mem , size ) ; 
    if ( unmem == -1 && mem != NULL){
        return -4;
    }
    int fdc = close( fd) ;
    if ( fdc  == -1){
        return -2 ;
    }
    return a ;
}