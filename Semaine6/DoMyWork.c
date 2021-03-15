//100% Inginious

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int doMyWork(void* long_computing(void*), void* backup_computing(void*), char* string, int ret_value){
  pthread_t my_t_1;
  int err = pthread_create(&my_t_1, NULL, long_computing,(void *) string);
  if(err != 0) return -1;
  int* res = long_computing(string);
  err = pthread_join(my_t_1,NULL);
  if(err != 0) return -2;
  if(*res != ret_value){
    pthread_t my_t_2;
    err = pthread_create(&my_t_2, NULL, backup_computing, (void *) string);
    if(err != 0) return -3;
    res = backup_computing(string);
    err = pthread_join(my_t_2, NULL);
    if(err != 0) return -4;
  }
  return *res;
}
