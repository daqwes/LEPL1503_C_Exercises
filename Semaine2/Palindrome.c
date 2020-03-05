

{ if (str == NULL) {
       return -1;
   }
 if (strlen(str) > 50) {
     return 1 ;
 }
   char *string = str ;
   char stri[(strlen(string)+1)*sizeof(char)];
   strcpy(stri,string) ;
   int count = 0;
   for (int i = 0; str[i]; i++) {
       if (stri[i] != ' ') {
           stri[count++] = stri[i]; 
            }
   }
   stri[count] = '\0';
   int i,l;
   l = strlen(stri);
   for(i=0; i<l/2; i++)
   {
     if ( stri[i] != stri[l-i-1] ) {
     return 0; 
     }
   }
   return 1;
}