#include<stdio.h>
void binary(void);
int main()
{
    struct DATE
    {
       unsigned int d:5;
       unsigned int m:4;
       unsigned int y:12;
    }d1={20,05,2016};
    //struct DATE d1={20,5,2016};
    printf("%d\n",sizeof(d1));
    printf("%d/%d/%d\n",d1.d,d1.m,d1.y);
    printf("binary of 2016 is ");
    binary();
    return 0;
}
void binary()
{
    int a=2016;
    int i,j,k,andmask;
    for(i=15;i>=0;i--)
    {
    j=i;
    andmask=1<<j;
    k=a&andmask;
    k==0?printf("0"):printf("1");
    }
}

