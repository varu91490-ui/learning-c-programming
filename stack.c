#include<stdio.h>
#include<stdlib.h>
#include<string.h>
# define MAX_SIZE 5
void push();
void pop();
void pali();
void display();
int stack[MAX_SIZE],top=-1;
int main()
{
    int choice;
    while(1)
    {
        printf("\n\n------STACK OPERATIONS-----\n");
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.palindrome\n");
        printf("4.display\n");
        printf("5.exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            pali();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}
void push()
{
    int item,n;
    if(top==(MAX_SIZE-1)){
        printf("Stack oerflow\n");}
    else{
        printf("Enter the element to be inserted:\n");
    scanf("%d",&item);
    top=top+1;
    stack[top]=item;}
}
void pop()
{
    int item;
    if(top==-1)
        printf("Stack underflow\n");
    else{
        item=stack[top];
    top=top-1;
    printf("The popped element is :%d",item);}
}
void pali()
{
    int digit,j,k,ind=0,flag=0,length=0,len=top+1;
    int num[len],rev[len],i=0;
    while(top!=-1)
    {
        digit=stack[top];
        num[i]=digit;
        i++;
        top--;
    }
    for(j=0;j<len;j++){
    printf("The stack elements are:%d\n",num[j]);
    }
for(k=len-1;k>=0;k--)
{
    rev[k]=num[ind];
    ind++;
}
printf("After reverse operation\n");
for(k=0;k<len;k++)
{
    printf("%d\n",rev[k]);
}
printf("Check for palindrome");
for(i=0;i<len;i++)
{
    if(num[i]==rev[i])
    {
        length=length+1;
    }
}
if(length==len)
{
    printf("The givn number is a palimdrome");
}
else
{
    printf("The given number is not a palindrome");
}
top=len-1;
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("Stack is empty");
    }
    else
    {
        for(i=top;i>=0;i--)
        {
            printf("Stack elements are:%d",stack[i]);
        }
    }
}
