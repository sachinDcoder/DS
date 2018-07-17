#include<stdio.h>
int min(int a[],int k,int n)
{
    int i,min,loc;
    min=a[k];
    loc=k;
    for(i=k+1;i<=n-1;i++)
        if(min>a[i])
        {
            min=a[i];
            loc=i;
        }
    return loc;
}
int main()
{
    int a[]={23,34,56,1,2,3,67,90,100,12,9};
    int j,temp,loc;
    for(j=0;j<=9;j++)
    {
        loc=min(a,j,11);
        temp=a[j];
        a[j]=a[loc];
        a[loc]=temp;
    }
    for(j=0;j<=10;j++)
       printf(" %d",a[j]);
    getch();
    return 0;
}
