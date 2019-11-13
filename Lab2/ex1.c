#include<stdio.h>
int Bitcount;
int main()
{
    unsigned int a=0;
    unsigned int max=~a;
    printf("max number:%u\n",max);
    return 0;
}
int bitcount(unsigned x)
{
    while ((x!=0))
    {
        x>>1;
        printf("max bit of number:%u\n");
        return 0;
    }
    
}

