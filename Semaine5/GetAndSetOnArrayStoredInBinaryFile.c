

  struct stat buf;
    int fd  =  open (filename , O_RDONLY );
    if ( fd == -1) {
        return -1 ;
    }
    int size = fstat( fd , &buf ) ; 
    if ( size == -1){
        return -1 ; 
    }
    size_t len = buf.st_size/sizeof(int);
          
    if ( index >= len ){ 
     close (fd);
     return -2 ; 
    }
    int *mem  = mmap (NULL, len*sizeof(int), PROT_READ, MAP_SHARED, fd, 0) ; 
    if ( mem == MAP_FAILED ){
        return -1 ; 
    }
    int rep = mem[index];
    int unmem =  munmap( mem , len ) ; 
    if ( unmem == -1 ){
        return -1;
    }
    int fdc = close( fd) ;
    if ( fdc  == -1){
        return -1 ;
    }
    return rep ;




{   struct stat buf;
    int fd  =  open (filename , O_RDWR | O_CREAT ) ;
    if ( fd == -1) {
        return;
    }
    int size = fstat( fd , &buf ) ; 
    if ( size == -1){
       return ; 
    }
    size_t len = buf.st_size/sizeof(int);
    if ( index >= len ){ 
        close(fd);
        return ;
    }
    int *mem  = mmap (NULL, len*sizeof(int), PROT_WRITE, MAP_SHARED, fd, 0) ; 
    if ( mem == MAP_FAILED ){
        return ; 
    }
    mem[index] = value ;   
    
    int unmem =  munmap( mem , len ) ; 
    if ( unmem == -1 ){
        return;
    }
    int fdc = close( fd) ;
    if ( fdc  == -1){
        return ;
    }
}