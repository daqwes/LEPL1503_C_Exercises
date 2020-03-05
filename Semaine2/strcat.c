#include <string.h>
{
    size_t dest_len = strlen(dest);
    size_t i;

    for (i = 0 ; src[i] != '\0' ; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';

    return dest;
}