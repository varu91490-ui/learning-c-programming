#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *left;
struct node *right;
};
struct node *createnode(int value)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct node *insert(struct node *root,int value)
{
    if(root==NULL){
        return createnode(value);
    }
    if(value<=root->data)
        root->left=insert(root->left,value);
    else if(value>=root->data){
        root->right=insert(root->right,value);
    }
    return root;
}
void preorder(struct node *root){
if(root==NULL){
    return;
}
printf("%d",root->data);
preorder(root->left);
preorder(root->right);
}
void postorder(struct node *root){
if(root==NULL)
    return;
postorder(root->left);
postorder(root->right);
printf("%d",root->data);
}
void inorder(struct node *root){
if(root==NULL)
    return;
inorder(root->left);
printf("%d",root->data);
inorder(root->right);
}
int search(struct node *root,int key)
{
    if(root==NULL)
        return 0;
    if(key==root->data)
        return 1;
    if(key<=root->data){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
}
int main()
{
    struct node *root=NULL;
    int value,key,choice;
    root=insert(root,6);
    root=insert(root,9);
    root=insert(root,5);
    root=insert(root,2);
    root=insert(root,8);
    root=insert(root,15);
    root=insert(root,24);
    root=insert(root,14);
    root=insert(root,7);
    root=insert(root,8);
    root=insert(root,5);
    root=insert(root,2);
   while(1)
   {
       printf("Binary tree menu\n");
       printf("1.Inordertraversal\n");
       printf("2.Preorder traversal\n");
       printf("3.postordertrevaersl\n");
       printf("4.Search for an element\n");
       printf("5.Exit\n");
       printf("Enter your choice:");
       scanf("%d",&choice);
       switch(choice)
       {
       case 1:
        printf("inorder traversal");
        inorder(root);
        printf("\n");
        break;
       case 2:
        printf("preorder traversal");
        preorder(root);
        printf("\n");
        break;
       case 3:
        printf("post oreder tevaersal");
        postorder(root);
        printf("\n");
        break;
       case 4:
        int key;
        printf("Enter the elemnet to sesrch:");
        scanf("%d",&key);
        if(search(root,key))
        {
            printf("The key is present in tree");
        }
        else {
            printf("The element is not found");
        }
        break;
       case 5:
        exit(0);
       }
   }
}
