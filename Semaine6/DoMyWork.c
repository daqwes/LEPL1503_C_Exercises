pthread_t thread1 ;
int a = pthread_create(&thread1,NULL,long_computing,(void*) string);
if (a ==-1 ) {
    return -1 ;
}
int* value1 = long_computing(string);
int b = pthread_join(thread1,NULL) ;
if (b==-1) {
    return -2 ;
}
if (*value1 == ret_value) {
    return *value1 ;
}
else {
    pthread_t thread2 ;
    int c = pthread_create(&thread2,NULL,backup_computing,(void*) string);
if (c ==-1 ) {
    return -3 ;
}
int *value2 = backup_computing(string);
int d = pthread_join(thread2,NULL) ;
if (d==-1) {
    return -4 ;
}
    return *value2 ;
}