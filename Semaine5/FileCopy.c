

 struct stat buf;
 int fd1 = open (file_name, O_RDONLY );
 if (fd1 < 0) {
   return -1;
 }
  int fst =fstat (fd1,&buf);
 if ( fst < 0) {
   return -1;
 }
 size_t size = buf.st_size ;
if(size == 0 ){
    int f2 = open(new_file_name,O_CREAT | O_RDWR, buf.st_mode) ;
    if(f2 == -1) return -1 ;
    if(close(fd1) == -1) return -1;
    if(close(f2) == -1) return -1;
    return -1 ;
}
 int *mp = mmap(NULL,size, PROT_READ, MAP_SHARED,fd1,0);
if(mp == MAP_FAILED) return -1 ;

int f2 = open(new_file_name, O_CREAT | O_RDWR, buf.st_mode) ;
if(f2 == -1) return -1 ;
if(ftruncate(f2,size)==-1) return -1 ;
void *addr = mmap(NULL,size,PROT_WRITE,MAP_SHARED,f2,0);
if(addr == MAP_FAILED) return -1 ;
memcpy(addr,mp, size) ;
if(close(fd1) == -1 ) return -1 ;
if(msync(addr , size, MS_SYNC ) == -1 ) return -1 ;
if(munmap(addr,size) == -1 ) return -1 ;
if(close(f2) == -1 ) return -1 ;
return 0 ;