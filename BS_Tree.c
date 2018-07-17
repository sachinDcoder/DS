/*Create binary search tree and implement Preorder, Inorder, Postorder and deletion recursively*/
#include<stdio.h>
#include<stdlib.h>
#define N NULL
typedef struct BST
{
    int d;
    struct BST *l,*r;
}tree;
tree* gn(int data)
{
    tree *x=(tree*)malloc(sizeof(tree));
    x->d=data;
    return x;
}
void insert(tree **root,int z)
{
    if(*root==N)
    {
        *root=gn(z);
        (*root)->l=(*root)->r=N;
    }
    else if((*root)->d > z)
        insert(&((*root)->l),z);
    else if((*root)->d < z)
        insert(&((*root)->r),z);
}
tree* findmin(tree *t)
{
    if(t==N)
        return;
    while(t->l!=N)
        t=t->l;
    return t;
}
void del(tree **root,int z)
{
    if(z <(*root)->d)
        del(&((*root)->l),z);
    else if(z >(*root)->d)
        del(&((*root)->r),z);
    else
    {
        if((*root)->l==N && (*root)->r==N)
        {
            tree *t=*root;
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
            del(&((*root)->r),t->d);
        }
    }
}
void preorder(tree *root)
{
    if(root==N)
        return;
    else
    {
        printf(" %d",root->d);
        if(root->l!=N)
            preorder(root->l);
        if(root->r!=N)
            preorder(root->r);
    }
}
void postorder(tree *root)
{
    if(root==N)
        return;
    else
    {
        if(root->l!=N)
            postorder(root->l);
        if(root->r!=N)
            postorder(root->r);
        printf(" %d",root->d);
    }
}
void inorder(tree *root)
{
    if(root==N)
        return;
    else
    {
        if(root->l!=N)
            inorder(root->l);
        printf(" %d",root->d);
        if(root->r!=N)
            inorder(root->r);
    }
}
int main()
{
    int choice,data;
    char ch;
    tree *root=N,*t=N;
    printf("Enter your data to create binary search tree\n");
    while(1)
    {
        fflush(stdin);
        scanf("%d",&data);
        insert(&root,data);
        printf("Wanna enter more??.. then enter y or Y.. (else any other key) : ");
        fflush(stdin);
        scanf("%c",&ch);
        if(ch== 'y' || ch== 'Y')
            continue;
        else
            break;
    }
    printf("Enter from the followings :\n");
    printf("1. insert an element\n");
    printf("2. delete an element\n");
    printf("3. find minimum of the elements\n");
    printf("4. display preorderly \n");
    printf("5. display inorderly \n");
    printf("6. display postorderly \n");
    printf("7. exit\n");
    while(1)
    {
        printf("\nEnter your choice from above : ");
        fflush(stdin);
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter your data to insert in the binary search tree\n");
                scanf("%d",&data);
                insert(&root,data);
                break;
            case 2:
                printf("Enter your data to delete from the binary search tree\n");
                scanf("%d",&data);
                del(&root,data);
                break;
            case 3:
                t=findmin(root);
                printf("The minimum of the elements is %d\n",t->d);
                break;
            case 4:
                printf("The preorder traversal of the BST :  ");
                preorder(root);
                break;
            case 5:
                printf("The inorder traversal of the BST :  ");
                inorder(root);
                break;
            case 6:
                printf("The postorder traversal of the BST :  ");
                postorder(root);
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("INVALID CHOICE");

        }
    }
    return 0;
}





