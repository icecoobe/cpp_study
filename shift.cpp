
#include <cstdint>
#include <stdio.h>


uint8_t rol(uint8_t num, size_t size)
{
    uint8_t temp = (num << size);
    num >>= (8 - size % 8);
    // num = num >> (8 - size % 8);
    return num | temp;
}

int main () 
{
    printf("%X\n", rol(0x5a, 3));
    return 0;
}
