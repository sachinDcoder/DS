/*create a priority queue and implement enqueue and dequeue*/
#include<stdio.h>
#include<stdlib.h>
typedef struct que
{
    int *a;
    int r,s;
}queue;
void init_queue(queue *q,int n)
{
    q->a=(int *)malloc(sizeof(int)*n);
    q->r=-1;
    q->s=n;
}
int isempty(queue *q)
{
    if(q->r==-1)
        return 1;
   else
        return 0;
}
int isfull(queue *q)
{
    if(q->r==(q->s)-1)
        return 1;
   else
        return 0;
}
void swap(int *a,int *b)
{
    int *c=(int *)malloc(sizeof(int));
    *c=*a;
    *a=*b;
    *b=*c;
}
void enPqueue(queue *q,int data)
{
    int c,p;
    if(isfull(q))
        return;
    else
    {
        q->r++;
        q->a[q->r]=data;
        c=q->r;
        while(c!=0)
        {
            p=(c-1)/2;
            if(q->a[c]>q->a[p])
                swap(&(q->a[c]),&(q->a[p]));
            else
                break;
            c=p;
        }
    }
}
int dePqueue(queue *q)//heap deletion
{
    int c,p,z;
    if(isempty(q))
        return;
    else
    {
        z=q->a[0];
        q->a[0]=q->a[q->r];
        q->r--;
        p=0;
        do
        {
            c=2*p+1;
            if(c > q->r)
                break;
            else
            {
                if(c < q->r && q->a[c] < q->a[c+1])
                    c++;
                if(q->a[p] < q->a[c])
                    swap(&(q->a[p]),&(q->a[c]));
                p=c;
            }
        }while(c < q->r);
    }
    return z;
}
int main()
{
    int data,i,n,z;
    queue q;
    printf("enter the size of the queue :");
    scanf("%d",&n);
    init_queue(&q,n);
    printf("enter the elements : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&data);
        enPqueue(&q,data);
    }
    printf("Sorted Elements are in decreasing order :");
    for(i=0;i<n;i++)
    {
        z=dePqueue(&q);
        printf(" %d",z);
    }
    return 0;
}



