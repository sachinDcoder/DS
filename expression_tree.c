#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define N NULL
typedef struct tree
{
    char d;
    struct tree *r,*l;
}tree;
typedef struct stack
{
    tree *data;
    struct stack *n;
}node;
int isempty(node *top)
{
    if(top==N)
        return 1;
    else
        return 0;
}
void push(node **top,tree *z)
{
    node *x=(node*)malloc(sizeof(node));
    x->data=z;
    x->n=*top;
    *top=x;
}
tree* pop(node **top)
{
    if(isempty(*top))
        return NULL;
    tree *tr;
    tr=(*top)->data;
    node *temp=*top;
    (*top)=(*top)->n;
    free(temp);
    return tr;
}
tree* peek(node *top)
{
    if(isempty(top))
        return NULL;
    else
        return (top->data);
}
tree* gn_tree(char ch)
{
    tree *x=(tree*)malloc(sizeof(tree));
    x->d=ch;
    x->r=x->l=N;
}
int prcd(char ch)
{
    if(ch=='*' || ch=='/' || ch=='%')
        return 3;
    else if(ch=='+' || ch=='-')
        return 2;
    else
        return 1;
}
void combine(node **tr,node **op)
{
    tree *temp=pop(op);
    temp->r=pop(tr);
    temp->l=pop(tr);
    push(tr,temp);
}
tree* construct(char a[])
{
    int i;
    node *tr=N;
    node *op=N;
    tree *temp=N;
    for(i=0;a[i]!='\0';i++)
    {
        if((a[i]>=48 && a[i]<=57)||(a[i]>=97 && a[i]<=122)||(a[i]>=65 && a[i]<=90))
        {
            temp=gn_tree(a[i]);
            push(&tr,temp);
        }
        else
        {
            switch(a[i])
            {
                case '(':
                    temp=gn_tree(a[i]);
                    push(&op,temp);
                    break;
                case ')':
                    while(peek(op)->d!='(')
                            combine(&tr,&op);
                    pop(&op);
                    break;
                default:
                    while((!isempty(op)) && prcd(peek(op)->d)>=prcd(a[i]))
                        combine(&tr,&op);
                    temp=gn_tree(a[i]);
                    push(&op,temp);
            }
        }
    }
    while(!isempty(op))
        combine(&tr,&op);
    return pop(&tr);
}
void inorder(tree *tr)
{
    if(tr==N)
        return;
    else
    {
        inorder(tr->l);
        printf("%c",tr->d);
        inorder(tr->r);
    }
}
void preorder(tree *tr)
{
    if(tr==N)
        return;
    else
    {
        printf("%c",tr->d);
        preorder(tr->l);
        preorder(tr->r);
    }
}
void postorder(tree *tr)
{
    if(tr==N)
        return;
    else
    {
        postorder(tr->l);
        postorder(tr->r);
        printf("%c",tr->d);
    }
}
int main()
{
    char s[20];
    printf("Enter your expression : ");
    gets(s);
    tree *tr=construct(s);
    printf("\n");
    preorder(tr);
    printf("\n");
    inorder(tr);
    printf("\n");
    postorder(tr);
}


