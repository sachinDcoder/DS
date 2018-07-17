#include<stdio.h>
#include<string.h>
typedef struct st
{
    char *a;
    int size,top;
}stack;
void init(stack *s,int n)
{
    s->a=(char *)malloc(sizeof(char)*n);
    s->size=n;
    s->top=-1;
}
int isempty(const stack *s)
{
    if(s->top==-1)
        return 1;
    else
        return 0;
}
int isfull(const stack *s)
{
    if(s->top==s->size)
        return 1;
    else
        return 0;
}
void push(stack *s,char z)
{
    if(!isfull(s))
        s->a[s->top++]=z;
    else
        return;
}
int pop(stack *s)
{
   if(isempty(s))
        return;
   else
        return s->a[s->top--];
}
int peek(stack *s)
{
    if(isempty(s))
        return;
   else
        return s->a[s->top];
}
int validity(stack *s,char a[])
{
    int i;
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]=='(')
            push(s,a[i]);
        else if(a[i]==')')
        {
            if(isempty(s))
                return 0;
            else
            {
                pop(s);
            }
        }
    }
    if(isempty(s))
        return 1;
    else
        return 0;
}
int prcd(char ch)
{
    if(ch=='*' || ch=='/')
        return 3;
    else if(ch=='+' || ch=='-')
        return 2;
    else
        return 1;
}
void convert(stack *s,char infx_str[])
{
    char pstfx_str[30];
    int i,j;
    char z;
    for(i=0,j=0;infx_str[i]!='\0';i++)
    {
        if(infx_str[i]>='0' && infx_str[i]<='9' || infx_str[i]>='a' && infx_str[i]<='b')
            pstfx_str[j++]=infx_str[i];
        else
        {
            switch(infx_str[i])
            {
                case '(':
                    push(s,infx_str[i]);
                    break;
                case ')':
                        do{
                            z=pop(s);
                            if(z!='(')
                                pstfx_str[j++]=z;
                        }while(z!='(');
                        break;
                default:
                    while(!isempty(s) && prcd(peek(s))>=prcd(infx_str[i]))
                        pstfx_str[j++]=pop(s);
                    push(s,infx_str[i]);
            }
        }
    }
    while(!isempty(s))
        pstfx_str[j++]=pop(s);
    pstfx_str[j]='\0';
    printf("\npostfix string is ");
        for(i=0;pstfx_str[i]!='\0';i++)
            printf("%c",pstfx_str[i]);
    //return pstfx_str;
}
main()
{
    stack s;
    char str[30],*p=NULL;
    int i;
    while(1)
    {
        printf("\nenter your expression : ");
        gets(str);
        init(&s,strlen(str));
        if(validity(&s,str))
        {
            printf("\nexpression is valid..so,");
            convert(&s,str);
        }
        else
            printf("\nexpression is invalid");
    }
    return 0;
}




