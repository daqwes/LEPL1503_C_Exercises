#include <string.h>
#include <stdlib.h>

int eq(int a, int b){
    return a!=b ;
}

int ge(int a, int b){
    return a<b ;
    
}

int gt(int a, int b ){
    return a<= b;
}

int le(int a, int b){
    return a>b ;
}

int lt (int a,int b ) {
    return a>=b ;
}

int ne(int a , int b){
    return a== b;
}


int main(int argc, char *argv[]){
    if(strcmp(argv[2], "-eq") == 0) return eq(atoi(argv[1]),atoi(argv[3]));
    else if(strcmp(argv[2], "-ge") == 0) return ge(atoi(argv[1]),atoi(argv[3]));
    else if(strcmp(argv[2], "-gt") == 0) return gt(atoi(argv[1]),atoi(argv[3]));
    else if(strcmp(argv[2], "-le") == 0) return le(atoi(argv[1]),atoi(argv[3]));
    else if(strcmp(argv[2], "-lt") == 0) return lt(atoi(argv[1]),atoi(argv[3]));
    else return ne(atoi(argv[1]),atoi(argv[3]));
}