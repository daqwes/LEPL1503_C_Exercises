//100% on Inginious


for(int i = 0 ; i< nb; i++){
    int a = pthread_mutex_lock(mutex) ;
    if (a != 0){
        return -1 ;
    }
    inc() ;
    int b = pthread_mutex_unlock(mutex);
    if (b!= 0 ){
        return -1;
    }
}
return 0 ;
