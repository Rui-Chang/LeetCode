#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

/// Due to #define INT32_MAX 2147483647
/// Reverse the number but remain the most significant digit.
/// The temporary ouptput must be sure not overflow after the
/// remaining digit inserted to its bottom.
int reverse(int x) {
    int reverseval = 0;

    //int32_t could not represents 2^31
    if(x == INT32_MIN)
        return 0;

    //Remain one digit in x.
    //eg. "102" converted to "20" leaving "1" in x.
    while(abs(x) > 9){
        reverseval = reverseval*10 + x%10;
        x /= 10;
    }

    if(abs(reverseval) > 214748364 ||
        ( abs(reverseval) == 214748364 && (x > 7 || x < -8) ))
        return 0;   //overflow

    reverseval = reverseval*10 + x;

    return reverseval;
}
