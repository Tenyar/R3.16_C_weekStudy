#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "chenillard-bits.h"
#include "dec_binary.h"

//  COMPILE CMD for POWER-SHELL : gcc -std=c99 -Wall -Wextra -g -o pascal pascal.c

unsigned char is_bulb_on(t_switch32 state, unsigned char bulb)
{
    // on 32 bits
    t_switch32 masque = 1 << bulb;
    //  Si le résultat est différent de zéro, cela signifie que le bit est à 1 (allumé).
    //  This code will return 1 if the specified bulb is on (bit set to 1) and 0 if it's off (bit set to 0) in the state. 
    //  & logic operator between two binary numbers.
    return ((state & masque) != 0);

    // Better method : return ((state >> bulb) & 1); with no mask.
    // In this method we are shifting state to the right by bulb (the goal is to have the one at the less signficiant bit : 0x0000[...]1).
    // Finally we check with the bitwise logic operation AND with 1 which is 0x0000000000000001 in binary and if the result == 1 then the bit at the index[bulb] is 1. 
    // For e.g with 1024 we're going to have after shifting  0x0000000000000001 with logic operator AND(&) with 1 :  0x0000000000000001
    // so  0x0000000000000001 + 0x0000000000000001 =  0x0000000000000001 with the & logic.
    // so at index[12] there's a 1.
}   

void afficher_chenillard(t_switch32 chenillard)
{

    int i = N_AMP-1; // le premier bit à l'index 0 compte.

    // On retourne à la ligne pour écraser / line break.
    printf("\r");
    while (i >= 0)
    {
        if (is_bulb_on(chenillard, i) == 1) 
        {
            printf("*");
        }
        else
        {
            printf(".");
        }
        i--;
    }
}

t_switch32 invert(t_switch32 state)
{
    //  Opérateur NOT au niveau du bit.
    return(~state); // inverting the bits
}

int main()
{   
    printf("\n");
    t_switch32 chenillard = 1024; // binaire = 1000-0000



    //  Series of quick test to understand how we work with the binaries representation.
    /*  
        char binary[32] = {'\0'};
        dec2bin(chenillard, binary);
        dec2bin(chennilardV2, binary);
        
        int test = is_bulb_on(chenillard, 8-1);
        printf("%d", test);
    */

    printf("---------- INVERT ----------");
    for (int i = 0; i < 10; i++)
    {   
        afficher_chenillard(chenillard);
        fflush(stdout);
        ms_sleep(300);
        afficher_chenillard(invert(chenillard));
        fflush(stdout);
        ms_sleep(300);
    }
    

    return EXIT_SUCCESS;
}
