#include<stdio.h>
typedef struct Que
{
    int *a;
    int s;
    int r,f;
}Queue;
void init(Queue *q,int s)
{
    q->a=(int *)malloc(sizeof(int)*s);
    q->s=s;
    q->r=q->f=-1;
}
int isfull(Queue *q)
{
    if(q->r==q->s-1 && q->f==0 || q->f==q->r+1)
        return 1;
    return 0;
}
int isempty(Queue *q)
{
    if(q->f==-1)
        return 1;
    return 0;
}
void enqueueR(Queue *q,int z)
{
    if(isfull(q))
        return;
    else
    {
        if(q->f==-1)
            q->f=0;
        if(q->r==q->s-1)
            q->r=0;
        else
            q->r++;
        q->a[q->r]=z;
    }
}
int dequeueF(Queue *q)
{
    int z;
    if(isempty(q))
        return;
    else
    {
        z=q->a[q->f];
        if(q->f==q->r)
            q->f=q->r=-1;
        else if(q->f==q->s-1)
            q->f=0;
        else
            q->f++;
    }
    return z;
}
void enqueueF(Queue *q,int z)
{
    if(isfull(q))
        return;
    else
    {
        if(q->r==-1)
        {
            q->f=0;
            q->r=q->s-1;
        }
        if(q->f==q->s-1)
            q->f=0;
        else
            q->f++;
        q->a[q->f]=z;
    }
}
int dequeueR(Queue *q)
{
    int z;
    if(isempty(q))
        return;
    else
    {
        z=q->a[q->r];
        if(q->r==q->f)
            q->r=q->r-1;
        else if(q->r==q->s-1)
            q->r=0;
        else
            q->r--;
        return z;
    }
}
main()
{
    Queue q;
    int choice,z,size;
    printf("enter the size\n");
    scanf("%d",&size);
    init(&q,size);
    printf("enter your choice from the followings\n");
    printf("1.insert an item from front\n");
    printf("2.insert an item from rear\n");
    printf("3.delete an item from front\n");
    printf("4.delete an item from rear\n");
    scanf("%d",&choice);
    while(1)
    {
        switch(choice)
        {
            case 1:
                printf("enter the item to be inserted at front\n");
                scanf("%d",&z);
                enqueueF(&q,z);
                break;
            case 2:
                printf("enter the item to be inserted at rear\n");
                scanf("%d",&z);
                enqueueR(&q,z);
                break;
            case 3:
                printf("the deleted item at front is %d",dequeueF(&q));
                break;
            case 4:
                printf("the deleted item at rear is %d",dequeueR(&q));
                break;
            default:
                printf("incorrect choice\n");
                break;
        }
    }
    return 0;
}




