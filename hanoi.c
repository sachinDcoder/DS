#include<stdio.h>
void toft(int ndishk,char source,char temp,char dest);
int main()
{
    char source='A',temp='B',dest='C';
    int ndisk;
    printf("Enter the number of disks : ");
    scanf("%d", &ndisk);
    printf("sequence is : \n");
    toft(ndisk,source,temp,dest);
    return 0;
}
void toft(int ndisk,char source,char temp,char dest)
{
    if(ndisk==1)
    {
        printf("move disk %d from %c-->%c\n",ndisk,source,dest);
        return;
    }
    toft(ndisk-1,source,dest,temp);
    printf("move disk %d from %c-->%c\n",ndisk,source,dest);
    toft(ndisk-1,temp,source,dest);
}
