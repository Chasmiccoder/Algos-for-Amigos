/*
Think of sizes as a wheel. If there's overflow, the variable gets assigned according
to how this wheel gets rotated.
*/

#include <stdio.h>
#include <limits.h>

int main() {

    printf("Size of integer in bytes: %d\n", sizeof(int));

    int var1 = INT_MIN;
    int var2 = INT_MAX;

    printf("Range of integer is from %d to %d\n", var1, var2);

    /*
    Unsigned Integer range is from 0 to 4294967295
    This is because int datatype is allocated 4 bytes of space (32 bits)
    and 2^32 = 4294967296

    Signed range is from [-2^31, 2^31 - 1]
    */

    unsigned int var3 = 0;
    unsigned int var4 = UINT_MAX;

    printf("Range of unsigned integer is from %u to %u\n", var3, var4);

    short int var5 = SHRT_MIN;
    short int var6 = SHRT_MAX;

    printf("Range of short integer is from %d to %d\n", var5, var6);

    unsigned short int var7 = 0;
    unsigned short int var8 = USHRT_MAX;

    printf("Range of unsigned short integer is from %u to %u\n", var7, var8);

    long int var9 = LONG_MIN;
    long int var10 = LONG_MAX;

    printf("Range of long integer is from %ld to %ld\n", var9, var10);

    long long int var11 = LLONG_MIN;
    long long int var12 = LLONG_MAX;

    printf("Range of long long integer is from %lld to %lld\n", var11, var12);

    unsigned long long int var13 = 0;
    unsigned long long int var14 = ULLONG_MAX;

    printf("Range of long long integer is from %llu to %llu\n", var13, var14);

    int exceed = INT_MAX + 1;
    printf("Exceeding int by 1: %d\n", exceed); // -2147483648

    exceed = INT_MAX + 2;
    printf("Exceeding int by 2: %d\n", exceed); // -2147483647

    exceed = INT_MIN - 1;
    printf("Exceeding minimum value of int by 1: %d\n", exceed); // 2147483647

    unsigned int u_exceed = UINT_MAX + 1;
    printf("Exceeding unsigned int by 1: %u\n", u_exceed); // 0

    u_exceed = UINT_MAX + 2;
    printf("Exceeding unsigned int by 2: %u\n", u_exceed); // 1 (performing a cycle)

    return 0;
}