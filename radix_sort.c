#include<stdio.h>
#include<malloc.h>
typedef struct Q
{
    int *a;
    int f,r;
    int n;
}queue;
void init_queue(queue *q,int n)
{
    q->a=(int *)malloc(sizeof(int)*n);
    q->f=q->r=-1;
    q->n=n;
}
int isempty_queue(queue *q)
{
    if(q->f==-1)
        return 1;
    else
        return 0;
}
int isfull_queue(queue *q)
{
    if(q->r+1==q->f || (q->r==q->n-1 && q->f==0))
        return 1;
    else
        return 0;
}
void enqueue(queue *q,int data)
{
    if(isfull_queue(q))
       return;
    else
    {
        if(q->f==-1)
            q->f=0;
        if(q->r==q->n-1)
            q->r=0;
        else
            q->r++;
        q->a[q->r]=data;
    }
}
int dequeue(queue *q)
{
    if(isempty_queue(q))
        return;
    else
    {
        int z=q->a[q->f];
        if(q->f==q->r)
            q->f=q->r=-1;
        else if(q->f==q->n-1)
            q->f=0;
        else
            q->f++;
        return z;
    }
}
int max_element(int a[],int n)
{
    int i,max=a[0];
    for(i=0;i<n;i++)
    {
        if(max<a[i])
            max=a[i];
    }
    return max;
}
int count_digit(int a)
{
    int c=0,r;
    if(a==0)
        return 1;
    while(a!=0)
    {
        r=a;
        r=r%10;
        a=a/10;
        c++;
    }
    return c;
}
void radix_sort(int a[],int n)
{
    int i,j,r,k=0;
    int m=max_element(a,n);
    int p=count_digit(m);
    queue q[19];
    for(i=0;i<19;i++)
        init_queue(&q[i],n);
    int d=1;
    for(i=1;i<=p;i++)
    {
        for(j=0;j<n;j++)
        {
            r=a[j]/d;
            r=r%10;
            enqueue(&q[r+9],a[j]);
        }
        d*=10;
        for(j=0;j<19;j++)
            while(!isempty_queue(&q[j]))
                a[k++]=dequeue(&q[j]);
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
    printf("\nradix sorted : ");
    radix_sort(a,n);
    for(i=0;i<n;i++)
        printf("%4d",a[i]);
}


