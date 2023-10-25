// Write a function to extract and return the six middle bits

#include <stdio.h>
#include <stdint.h>

uint32_t six_middle_bits(uint32_t u) {

    /*
    
    ____ ____ ____ ____ ____ ____ ____ ____ 
    ____ ____ ____ _XXX XXX_ ____ ____ ____ 
    
    */
    
    // Method 1
    // Mask: 0000 0000 0000 0000 0000 0000 0011 1111
    uint32_t mask = 0x3F;
    return (u & (mask << 13)) >> 13;
    
    // Method 2 (ideal)
    uint32_t mask = 0x3F;
    return (u >> 13) & mask;
    
    // Method 3 (hacky)
    return (u << 13) >> 26;
}
