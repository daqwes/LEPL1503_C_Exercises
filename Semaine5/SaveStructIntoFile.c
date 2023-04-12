// 55% -  NOT FINISHED


    int fd = open ( filename,  O_RDWR | O_CREAT | O_TRUNC ) ;
    if (fd == -1) {
        return fd ;
    }  
    int ftr = ftruncate(fd,sizeof(point_t)*size) ;
    if (ftr == -1) {
        return -6 ;
   
    }
    void *mem = mmap (NULL, sizeof(point_t)*size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0) ; 
    if (mem == (void*)-1) {
        return -3 ;
    }
    memcpy (mem, pt, sizeof(point_t)*size);
    int fin = msync(mem,sizeof(point_t)*size, MS_ASYNC) ;
    if (fin == -1) {
        return -5 ; 
    }
    int cl = munmap(mem,sizeof(point_t)*size)  ; 
    if (cl == -1){ 
    return -4 ;
    }
    int fc = close(fd) ; 
    if ( fc == -1 ){
        return -2 ;
    }


    return 0 ;
    
