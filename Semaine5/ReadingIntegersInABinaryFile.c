

{   struct stat buf ;
    int fd  =  open (filename , O_RDONLY) ;
    int a = 0 ;
    if ( fd == -1) {
        return -1 ;
    }
    int size = fstat( fd , &buf ) ; 
    if ( size == -1){
        return -5 ; 
    }
    size_t len = buf.st_size ;
    if(len== 0 ){
        close(fd) ;
        return 0 ;
    }
    int *mem  =  mmap (NULL, len, PROT_READ, MAP_SHARED, fd, 0) ; 
     
    if ( mem == MAP_FAILED ){
        return -3 ; 
    }
    for ( int i = 0 ; i < len/sizeof(int) ; i++) {
        a += mem[i] ;  
    }
    int unmem =  munmap( mem , len ) ; 
    if ( unmem == -1 ){
        return -4;
    }
    int fdc = close( fd) ;
    if ( fdc  == -1){
        return -2 ;
    }
    return a ;
}