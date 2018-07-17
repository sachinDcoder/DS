#include<stdio.h>
#include<malloc.h>
void shell_sort(int a[],int n)
{
    int i,j,g=n/2,z;
    while(g>0)
    {
        for(i=g;i<n;i++)
        {
            z=a[i];
            for(j=i-g;j>=0 && a[j]>z;j-=g)
            {
                a[j+g]=a[j];
                a[j]=z;
            }
        }
        g=g/2;
    }
}
int main()
{
    int *a,i,n;
    printf("Enter the no. of elements you would enter : ");
    scanf("%d",&n);
    a=(int *)malloc(sizeof(int)*n);
    printf("Enter the elements :\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("You have entered : ");
    for(i=0;i<n;i++)
        printf("%4d",a[i]);
    printf("\nShell sorted : ");
    shell_sort(a,n);
    for(i=0;i<n;i++)
        printf("%4d",a[i]);
}
