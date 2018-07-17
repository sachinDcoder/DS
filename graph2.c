/*graph dfs and bfs*/
#include<stdio.h>
#include<stdlib.h>

typedef struct st
{
    int *a;
    int top;
    int n;
}stack;
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
void init_stack(stack *s,int n)
{
    s->a=(int *)malloc(sizeof(int)*n);
    s->top=-1;
    s->n=n;
}
int isempty_stack(stack *s)
{
    if(s->top==-1)
        return 1;
    else
        return 0;
}
int isfull_stack(stack *s)
{
    if(s->top==s->n-1)
        return 1;
    else
        return 0;
}
void push(stack *s,int data)
{
    if(isfull_stack(s))
        return;
    else
        s->a[++s->top]=data;
}
int pop(stack *s)
{
    if(isempty_stack(s))
        return;
    else
       return s->a[s->top--];
}
int isAllvisited(int f[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(f[i]==0)
            return 0;
    }
    return 1;
}
void dfs(int *a[],int n)
{
    int i,j;
    stack s;
    init_stack(&s,n);
    int f[n];
    for(i=0;i<n;i++)
        f[i]=0;
    push(&s,0);
    while(!isAllvisited(f,n))
    {
        i=pop(&s);
        if(f[i]!=1)
        {
            printf(" %d",i);
            f[i]=1;
            for(j=0;j<n;j++)
                if(a[i][j]==1 && f[j]!=1)
                    push(&s,j);
        }
    }
}
void bfs(int *a[],int n)
{
    int i,j;
    queue q;
    init_queue(&q,n);
    int f[n];
    for(i=0;i<n;i++)
        f[i]=0;
    enqueue(&q,0);
    while(!isAllvisited(f,n))
    {
        i=dequeue(&q);
        if(f[i]!=1)
        {
            printf(" %d",i);
            f[i]=1;
        }
        for(j=0;j<n;j++)
        {
            if(a[i][j]==1 && f[j]!=1)
                enqueue(&q,j);
        }
    }
}
int checkcycle(int *a[],int n)
{
    int i,j;
    stack s;
    init_stack(&s,n);
    int f[n];
    for(i=0;i<n;i++)
        f[i]=0;
    push(&s,0);
    while(!isAllvisited(f,n)||!isempty_stack(&s))
    {
        i=pop(&s);
        if(f[i]!=1)
        {
            f[i]=1;
            for(j=0;j<n;j++)
                if(a[i][j]==1 && f[j]!=1)
                    push(&s,j);
        }
        else
            return 1;
    }
    return 0;
}
int main()
{
    int n,i,j;
    printf("Enter the no of nodes : ");
    scanf("%d",&n);
    int *a[n],k=n;
    for(i=0;i<k;i++)
        a[i]=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++){
            printf("Enter the value at a[%d][%d] : ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nThe adjacency matrix of the graph according to given data as follow : \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%5d",*(*(a+i)+j));
        printf("\n");
    }
    printf("dfs : ");
    dfs(a,n);
    printf("\n");
    printf("bfs : ");
    bfs(a,n);
    printf("\n");
    if(checkcycle(a,n))
        printf("Yes,there is cycle.\n");
    else
        printf("No,there is no cycle.\n");
    return 0;
}




