#include<stdio.h>
#include<stdlib.h>
struct binaryTreeNode
{
    int info;
    struct binaryTreeNode *left,*right;
};
struct binaryTreeNode* createBinaryTree(struct binaryTreeNode *root)
{
    int n;
    static i;
    root=(struct binaryTreeNode*)malloc(sizeof(struct binaryTreeNode));
    if(root==NULL)
        printf("sorry..node can't be created any more");
    else
    {
    printf("Enter the info for %dst node : ",++i);
    scanf("%d",root->info);
    printf("Enter 0 for termination or leaf :");
    scanf("%d",n);
       if(!n)
           root->left=root->right=NULL;
       else
      {
           createBinaryTree(root->left);
           createBinaryTree(root->right);
      }
    }
    return root;
}
void perOrder(struct binaryTreeNode *root)
{
    if(root!=NULL)
    {
        printf("%d\n",root->info);
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main()
{
    struct binaryTreeNode *root;
    root=createBinaryTree(root);
    perOrder(root);
    return 0;
}








