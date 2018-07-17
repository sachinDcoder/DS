#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef struct st
{
    char *a;
    int top;
    int size;
}stack;
void init(stack *s,int n)
{
    s->a=(char*)malloc(sizeof(char)*n);
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
int isfull(stack *s)
{
    if(s->top==s->size-1)
        return 1;
    else
        return 0;
}
void push(stack *s,char z)
{
    if(isfull(s))
        return;
    else
        s->a[++s->top]=z;
}
char pop(stack *s)
{
    if(isempty(s))
        return 0;
    else
        return(s->a[s->top--]);
}
char peek(stack *s)
{
    if(isempty(s))
        return 0;
    else
        return(s->a[s->top]);
}
int isbalanced_brackets(char a[])
{
    stack s;
    init(&s,strlen(a));
    int i;
    char c;
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]=='(' || a[i]=='[' || a[i]=='{')
            push(&s,a[i]);
        else if(a[i]==')')
        {
            if(peek(&s)!='(' || isempty(&s))
                return 0;
            c=pop(&s);
        }
        else if(a[i]=='}')
        {
            if(peek(&s)!='{' || isempty(&s))
                return 0;
            c=pop(&s);
        }
        else if(a[i]==']')
        {
            if(peek(&s)!='[' || isempty(&s))
                return 0;
            c=pop(&s);
        }
    }
    if(isempty(&s))
            return 1;
        else
            return 0;
}
int main(){
    int t,i;
    scanf("%d",&t);
    int a0;
    for( a0 = 0; a0 < t; a0++)
    {
        char* s = (char *)malloc(10240 * sizeof(char));
        scanf("%s",s);
        i=isbalanced_brackets(s);
        if(i==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
