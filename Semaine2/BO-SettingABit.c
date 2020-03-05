
{   bool bit  = x & 1 << pos ;
    if (bit != value ){
    x ^= 1 << pos ;
    return x ;
    }
    else{
        return x ;
    }
}