return (int) ((((points_t *)s1)->average - ((points_t *)s2)->average)*1000) ;




int f = open(filename,O_RDWR) ;
if(f == -1 )return -1 ;
struct stat buf ;
if(fstat(f,&buf) == -1 ){
    close(f) ;
    return -5;
}
size_t len = buf.st_size ;
points_t *adr = mmap (NULL, len , PROT_READ|PROT_WRITE, MAP_SHARED,f,0) ;
if (adr == MAP_FAILED) {
    close(f) ;
    return -2;
}
for(int i =0 ; i < len/sizeof(points_t) ;i++) {
    adr[i].average = (adr[i].LEPL1103+adr[i].LEPL1203 + adr[i].LEPL1108 + adr[i].LEPL1302 + adr[i].LEPL1402)/5 ;
}
qsort(adr, len/sizeof(points_t),sizeof(points_t),compar) ;
if(msync(adr,len,MS_SYNC) == -1) {
    munmap(adr,len) ;
    close(f) ;
    return -4 ;
}
if (munmap(adr, len) == -1 ) {
    close(f) ;
    return -3 ;
}
if(close(f) == -1 ) return -6 ;
return 0 ;