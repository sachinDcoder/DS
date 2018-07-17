#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct st
{
    int *a;
    int top;
    int size;
}stack;
void init(stack *s,int n)
{
    s->a=(int*)malloc(sizeof(int));
    s->top=-1;
    s->size=n;
}
int isempty(stack *s)
{
    if(s->top==-1)
        return 1;
    else
        return 0;
}
int isfull(const stack *s)
{
    if(s->top==s->size-1)
        return 1;
    else
        return 0;
}
void push(stack *s,int d)
{
    if(isfull(s))
        return;
    else
        s->a[++s->top]=d;
}
int pop(stack *s)
{
    if(isempty(s))
        return -9999;
    else
       return(s->a[s->top--]);
}
int findmax(stack *s)
{
    int max=s->a[0],data,i,t=s->top;
    for(i=0;i<=t;i++)
    {
        if(max < s->a[i])
            max=s->a[i];
    }
    return max;
}
int main()
{
    stack s;
    int data,choice,n;
    printf("Enter the size : ");
    scanf("%d",&n);
    init(&s,n);
    do{
            printf("Enter choice(1.insert 2.pop 3.max): ");
            scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("Enter the data to insert : ");
            scanf("%d",&data);
            push(&s,data);
            break;
        case 2:
            data=pop(&s);
            break;
        case 3:
            printf("%d\n",findmax(&s));
            break;
    }
    }while(choice!=4);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
