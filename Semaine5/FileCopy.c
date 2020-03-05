// 58% - NOT FINISHED 

 struct stat file_stat;
 // ouverture fichier source
 int fd1 = open (file_name, O_RDWR );
 if (fd1 < 0) {
   return -1;
 }
  int fst =fstat (fd1,&file_stat);
 if ( fst < 0) {
   return -1;
 }
 // ouverture fichier destination
 int fd2 =  open (new_file_name, O_RDWR );
 if (fd2< 0) {
   return -1;
 }



 // mmap fichier source
 void *src = mmap (NULL, file_stat.st_size, PROT_READ | PROT_WRITE,        MAP_SHARED, fd1, 0);
 if (src   == NULL) {
   return -1;
 }

 // mmap fichier destination
 void *dst = mmap (NULL, file_stat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd2, 0);
 if (dst  == NULL) {
   return -1;
 }
ftruncate(fd2,file_stat.st_size);

 // copie complète
 memcpy (dst, src, file_stat.st_size);
int fin = msync(dst,file_stat.st_size, MS_ASYNC) ;
    if (fin == -1) {
        return -1 ; 
    }
 // libération mémoire
 int free1 = munmap(src,file_stat.st_size);
 if(free1<0) {
   return -1;
 }
 int free2 = munmap(dst,file_stat.st_size);
 if(free2<0) {
   return -1;
 }
 // fermeture fichiers
 int cl1 = close(fd1);
 if(cl1<0) {
   return -1;
 }
 int cl2 = close(fd2) ;
 if(cl2<0) {
   return -1;
 }
 return 0;