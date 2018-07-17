#include<stdio.h>
#define MAX 50
int binsearch(int *,int ,int );
void sort(int *,int);
int main()
{
    int i,j,n,arr[MAX],item,index;
    printf("enter the no. of elements\n");
    scanf("%d",&n);
    printf("enter the elements\n");
    for(i=0;i<n;i++)
    {
        printf("enter the %dst element : ",i+1);
        scanf("%d",&arr[i]);
        printf("\n");
    }
    sort(arr,n);
    printf("the sorted arr is ");
    for(i=0;i<n;i++)
        printf("%d\t",arr[i]);
    printf("\n");
    printf("enter the item to be searched : ");
    scanf("%d",&item);
    index=binsearch(arr,n,item);
    if(index == -1)
        printf("item not found");
    else
        printf("item %d at %d index in the sorted array \n\n",item,index);
    return 0;
}
void sort(int arr[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-1-i;j++)
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
}
int binsearch(int arr[],int n,int item)
{
    int Ub,Lb,mid;
    Lb=0;
    Ub=n-1;
    while(Lb<=Ub)
    {
        mid=(Ub+Lb)/2;
        if(item<arr[mid])
        {
            Ub=mid-1; //search in left side
        }
        else if(item>arr[mid])
        {
            Lb=mid+1; //search in right side
        }
        else
            return mid;
    }
    return -1;
}
