#include<stdio.h>
#include<stdlib.h>
#define N NULL
typedef struct tr
{
    int d;
    struct tr *l,*r;
    int b;
}tree;
tree* gn(int data)
{
    tree *x=(tree*)malloc(sizeof(tree));
    x->l=N;
    x->r=N;
    x->b=0;
    x->d=data;
    return x;
}
int depth(tree *root)
{
    if(root==N)
        return 0;
    else
    {
        int lh=depth(root->l);
        int rh=depth(root->r);
        return(1+(lh>rh?lh:rh));
    }
}
void bfactor(tree *root)
{
    if(root==N)
        return;
    else
    {
        int lh=depth(root->l);
        int rh=depth(root->r);
        root->b=lh-rh;
        if(root->l!=N)
            bfactor(root->l);
        if(root->r!=N)
            bfactor(root->r);
    }
}
void left_rotation(tree **root)
{
    if(*root==N)
        return;
    else
    {
        tree *temp=(*root)->r->l;
        (*root)->r->l=(*root);
        (*root)=(*root)->r;
        (*root)->l->r=temp;
    }
}
void right_rotation(tree **root)
{
    if(*root==N)
        return;
    else
    {
        tree *temp=(*root)->l->r;
        (*root)->l->r=*root;
        *root=(*root)->l;
        (*root)->r->l=temp;
    }
}
void balance_node(tree **root)
{
    if((*root)->b==2)
    {
        if((*root)->l->b==-1)
            left_rotation(&((*root)->l));
        right_rotation(root);
        bfactor(*root);
    }
    else if((*root)->b==-2)
    {
        if((*root)->r->b==1)
            right_rotation(&((*root)->r));
        left_rotation(root);
        bfactor(*root);
    }
    else
        return;
}
void insert_node(tree **root,int data)
{
    if(*root==N)
        *root=gn(data);
    else if(data < (*root)->d)
        insert_node(&((*root)->l),data);
    else if(data > (*root)->d)
        insert_node(&((*root)->r),data);
    bfactor(*root);
    balance_node(root);
}
tree* findmin(tree *root)
{
    if(root==N)
        return;
    while(root->l!=N)
        root=root->l;
    return root;
}
void delete_node(tree **root,int z)
{
    if(*root==N)
        return;
    else if(z < (*root)->d)
        delete_node(&((*root)->l),z);
    else if(z > (*root)->d)
        delete_node(&((*root)->r),z);
    else
    {
        if((*root)->l==N && (*root)->r==N)
        {
            tree *t=*root;
            *root=N;
            free(t);
        }
        else if((*root)->l!=N && (*root)->r==N)
        {
            tree *t=*root;
            *root=(*root)->l;
            free(t);
        }
        else if((*root)->l==N && (*root)->r!=N)
        {
            tree *t=*root;
            *root=(*root)->r;
            free(t);
        }
        else
        {
            tree *t=findmin((*root)->r);
            (*root)->d=t->d;
            delete_node(&((*root)->r),t->d);
        }
    }
    if(*root!=N)
    {
        bfactor(*root);
        balance_node(root);
    }
}
void inorder(tree *root)
{
    if(root==N)
        return;
    else
    {
        inorder(root->l);
        printf(" %d",root->d);
        inorder(root->r);
    }
}
void preorder(tree *root)
{
    if(root==N)
        return;
    else
    {
        printf(" %d",root->d);
        preorder(root->l);
        preorder(root->r);
    }
}
void postorder(tree *root)
{
    if(root==N)
        return;
    else
    {
        postorder(root->l);
        postorder(root->r);
        printf(" %d",root->d);
    }
}
int main()
{
    tree *root=N;
    int choice,data;
    do{
    printf("1. insert a node in AVL Tree \n");
    printf("2. delete a node from AVL Tree \n");
    printf("3. traversal \n");
    printf("4.  exit\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("Enter the data to be inserted in AVL Tree : ");
            scanf("%d",&data);
            insert_node(&root,data);
            break;
        case 2:
            printf("Enter the element to be deleted in AVL Tree : ");
            scanf("%d",&data);
            delete_node(&root,data);
            break;
        case 3:
            printf("\n Preorder : ");
            preorder(root);
            printf("\n inorder : ");
            inorder(root);
            printf("\n postorder : ");
            postorder(root);
            printf("\n");
            break;
    }
    }while(choice!=4);
}

