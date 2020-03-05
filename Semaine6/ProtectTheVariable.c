// 33% - NOT FINISHED 


for(int i = 0 ; i< nb; i++){
    int a = pthread_mutex_lock(mutex) ;
    if (a == -1){
        return -1 ;
    }
    inc() ;
    int b = pthread_mutex_unlock(mutex);
    if (b==-1){
        return -1;
    }
}
return 0 ;