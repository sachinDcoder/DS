#include<stdio.h>
#include<stdlib.h>
struct ArrayStack
{
    int top;
    int capacity;
    int *array;
};
struct ArrayStack *createStack(int cap)
{
    struct ArrayStack *stack;
    stack=(struct ArrayStack*)malloc(sizeof(struct ArrayStack));
    stack->capacity=cap;
    stack->top=-1;
    stack->array=(int *)malloc(sizeof(int)*stack->capacity);
    return(stack);
};
int full(struct ArrayStack *stack)
{
    if(stack->top==(stack->capacity)-1)
        return 1;
    else
        return 0;
}
int empty(struct ArrayStack *stack)
{
    if(stack->top==-1)
        return 1;
    else
        return 0;
}
void push(struct ArrayStack *stack,int item)
{
    if(!full(stack))
    {
        stack->top++;
        stack->array[stack->top]=item;
    }
    else
        printf("\nsry..stack is full..last value can't be pushed..now can't pushed any more\n");
}
int pop(struct ArrayStack *stack)
{
    int item;
    if(!empty(stack))
    {
        item=stack->array[stack->top];
        stack->top--;
        return item;
    }
    else
        return(-1);
}
int main()
{
    int item,choice,i;
    struct ArrayStack *stack;
    stack=createStack(3);
    printf("\n1. push");
    printf("\n2. pop");
    printf("\n3. display");
    printf("\n4. exit");
    while(1)
    {
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\n Enter the no. to be pushed : ");
                scanf("%d",&item);
                push(stack,item);
                break;
            case 2:
                item=pop(stack);
                if(item==-1)
                    printf("\nstack is empty..");
                else
                    printf("\nthe popped value is %d",item);
                break;
            case 3:
                printf("the stack is ");
                for(i=0;i<=stack->top;i++)
                    printf("%d  ",stack->array[i]);
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}
