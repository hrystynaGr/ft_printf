#include "ft_printf.h"
int main()
{ 
    //char
    printf("m: %%\n");
    ft_printf("m: %%\n");

    //string
    printf("'mama ama': %s!\n", "mama ama ");
    ft_printf("'mama ama': %s!\n", "mama ama ");

    //digit
    printf("digit: %i\n", -657);
    ft_printf("digit: %i\n", -657);

    //pointer
    unsigned long int i = 2;
    unsigned long int *pntr = &i;
    printf("digit: %p\n", pntr);
    ft_printf("pntr: %p\n", pntr);
    // ft_printf("digit: %d\n", pntr);

    // //u
    // unsigned long int uli = 4294967293;
    // printf("uli: %lu\n", uli);
    // ft_printf("uli: %u\n", uli);
    // return 0;

    //hex
    // unsigned char a=0xFAFA;
    // // printf("xD");
    // printf("hex  x: %x\n", a);
    // ft_printf("hex  x: %x\n", a);
    // printf("hex  X: %X\n", a);
    // ft_printf("hex  X: %X\n", a);
}