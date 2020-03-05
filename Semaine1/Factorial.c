int factorial(int a) {
    if (a == 0){
        return 1;
    }
    else {
        int b = 1; 
        for(int i = 1;i<a+1;i++){
          b = b*i;
        }
        return b;
    }
}
