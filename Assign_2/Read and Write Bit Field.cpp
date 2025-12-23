#include <stdint.h>
#include <stdio.h>

void printBinary(uint8_t n)
{
    uint8_t mask;
    for (mask = 0x80; mask > 0; mask >>= 1)
        printf("%d", (n & mask) ? 1 : 0);
    printf("\n");
}

int main(void)
{
    uint8_t reg = 0xAA;   // 1010 1010
    uint8_t field;

    printf("Before modification:\n");
    printBinary(reg);

   
    field = (reg >> 2) & 0x07;  
    printf("\nRead bits 2 to 4 = 0b%03d\n", field);

    reg = reg & ~(0x07 << 2); 
    printf("\nclear 2 to 4:\n");
    printBinary(reg);   
  
   reg = reg | (0x03 << 2);     // 0b011 into bits 2 to 4 
    printf("\nAfter modification:\n"); 
    printBinary(reg);

    return 0;
}

