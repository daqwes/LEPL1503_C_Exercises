int cmp_func(uint8_t func1(uint8_t n),uint8_t func2(uint8_t n)){
    unsigned int i = 0 ;
    for (;i<256;i++){
        if (func1(i) == func2(i)) {
            ;
        } 
        else if (func1 == func2){
            return 1;
        }
        else {
            return 0 ;
        }
    }
    return 1;
}