#include<stdio.h>
#include<stdlib.h>
#define N NULL
typedef struct queue
{
    char d;
    int p;
    struct queue *n;
}node;
node* gn(char data,int pri)
{
    node *x=(node *)malloc(sizeof(node));
    x->p=pri;
    x->d=data;
    return x;
}
void insert(node **h,char data,int pri)
{
    node *t=*h,*x=gn(data,pri);
    if(*h==N || (*h)->p > pri)
    {
        x->n=*h;
        *h=x;
    }
    else
    {
        while(t->n!=N && t->n->p <= pri)
            t=t->n;
        x->n=t->n;
        t->n=x;
    }
}
char del_Front(node **h)
{
    char z;
    if(*h==N)
        return '0';
    else
    {
        node *t=*h;
        z=(*h)->d;
        *h=(*h)->n;
        free(t);
    }
    return z;
}
int main()
{
    char data;
    int priority;
    node *h=N;
    printf("Enter your data (0 to terminate) and priority : \n");
    while(1)
    {
        printf("Enter data : ");
        scanf("%s",&data);
        if(data=='0')
            break;
        printf("Enter its priority : ");
        scanf("%d",&priority);
        printf("\n");
        insert(&h,data,priority);
    }
    while(1)
    {
        data=del_Front(&h);
        if(data=='0')
            break;
        printf("%4c\n",data);
    }
    return 0;
}
