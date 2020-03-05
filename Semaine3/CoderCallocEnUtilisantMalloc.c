{   int *a = malloc(size*nmemb);
 if (a == NULL) {
     return NULL;
 }
    for (int i = 0; i<nmemb;i++){
        a[i] = 0;
    }
 
    return a;
    free(a);
}