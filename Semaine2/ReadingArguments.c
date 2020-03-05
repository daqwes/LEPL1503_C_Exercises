#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    if (argv[1] == NULL){
        return 1;
        
    }
    else {
        for (int i = 1;argv[i] != NULL;i = i+2 ){
            printf("%s ",argv[i]);
            
        }
        return 0 ;
    }
}