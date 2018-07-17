#include<stdio.h>
#include<malloc.h>
#define N NULL
typedef struct stack
{
    int d;
    struct stack *n;
}node;
node* gn(int data)
{
    node *x=(node *)malloc(sizeof(node));
    x->d=data;
    return x;
}
int isempty(node **top)
{
    if(*top==N)
        return 1;
    else
        return 0;
}
void push(node **top,int data)
{
    node *x=gn(data);
    if(x==N)
        return;
    x->n=*top;
    *top=x;
}
int pop(node **top)
{
    if(isempty(top))
        return 9999;
    else
    {
        node *temp=*top;
        int z=(*top)->d;
        (*top)=(*top)->n;
        free(temp);
        return z;
    }
}
int peek(node *top)
{
    if(top!=N)
        return(top->d);
    else
        return 9999;
}
void delstack(node **top)
{
    if(top==N)
        return;
    while(*top!=N)
    {
        node *temp=*top;
        *top=(*top)->n;
        free(temp);
    }
}
int main()
{
    int choice,data;
    node *top=N;
    while(1)
    {
        printf("Enter your choice \n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Delete Stack\n");
        printf("5. Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to push : ");
                scanf("%d",&data);
                push(&top,data);
                break;
            case 2:
                data=pop(&top);
                if(data==9999)
                    printf("Stack is empty\n");
                else
                    printf("The popped element is %d\n",data);
                break;
            case 3:
                data=pop(&top);
                if(data==9999)
                    printf("Stack is empty\n");
                else
                    printf("The peek element is %d\n",data);
                break;
            case 4:
                delstack(&top);
                break;
            case 5:
                exit(0);
        }
    }
    return 0;
}
