#include<stdio.h>
#include<stdlib.h>
int key[20],n,m;
int *ht,index;
int count=0;
void insert(int key)
{
    index=key%m;
    while(ht[index]!=-1){
        index=(index+1)%m;
    }
    ht[index]=key;
    count++;
}
void display()
{
    if(count==0)
    {
        printf("Hash table is empty");
        return;
    }
        printf("The hash table elements are:\n");
        for(int i=0;i<m;i++){
            printf("\nT[%d]->%d",i,ht[i]);
        }
    }
void main()
{
    int i;
    printf("enter the no of employee records:");
    scanf("%d",&n);
    printf("Enter the two digits size of hash table:");
    scanf("%d",&m);
    ht=(int*)malloc(m*sizeof(int));
    for(int i=0;i<m;i++){
        ht[i]=-1;
    }
    printf("Enter the four digit key ");
    for(int i=0;i<n;i++){
        scanf("%d",&key[i]);
    }
    for(int i=0;i<n;i++){
        if(count==m){
            printf("Hash table is full cannot insert key %d",i+1);
            break;
        }
            insert(key[i]);
    }
    display();
}
