

if ( len == *in){
    return -1 ;
}
 if ( (*in) == 0 ){
    (*first) = * last ;
 }
buf[(*last)++] =d ;
if(*last >= len) *last = 0 ;
(*in)++ ;
return 0 ;




if(*in == 0 ) return NULL ;
data_t *rep = buf[*first] ;
buf[(*first)++ ] = NULL ;
if((*first) >= len) *first = 0 ;
(*in)-- ;
return rep ;