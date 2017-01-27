#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    //Binary value of character
    int aVal, bVal;
    int i = strlen(a);
    int j = strlen(b);
    int pos = (i > j)? i+1: j+1;
    char *returnStr = (char *)malloc((pos+1) * sizeof(char));
    int sum = 0;

    returnStr[0] = returnStr[1] = '0';
    returnStr[pos] = '\0';

    while(i > 0 || j > 0 || sum){
        aVal = (--i >= 0)? (a[i] - '0'): 0;
        bVal = (--j >= 0)? (b[j] - '0'): 0;
        sum = aVal + bVal + sum;
        returnStr[--pos] = ((char)sum & 0x1) + '0';
        //carry bit
        sum >>= 1;
    }

    //No more carry in most significant bit
    if(pos == 1)
        returnStr++;

    return returnStr;
}
