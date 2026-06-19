#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct employee{
char SSN[20];
char name[20];
char dept[20];
char designation[20];
double sal;
char phno[15];
struct employee *next;
struct employee *prev;
};
struct employee *createemployee(char SSN[],char name[],char dept[],char designation[],double sal,char phno[])
{
    struct employee *newemployee=(struct employee*)malloc(sizeof(struct employee));
    if(newemployee==NULL)
    {
        printf("Memory allocation fsiled\n");
        exit(1);
    }
    strcpy(newemployee->SSN,SSN);
    strcpy(newemployee->name,name);
    strcpy(newemployee->dept,dept);
    strcpy(newemployee->designation,designation);
    newemployee->sal,sal;
    strcpy(newemployee->phno,phno);
    newemployee->next=NULL;
    newemployee->prev=NULL;
    return newemployee;
}
struct employee *insertend(struct employee *head,struct employee *newemployee)
{
    if(head==NULL){
    return newemployee;}
    struct employee *current=head;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next=newemployee;
    newemployee->prev=current;
    return head;
}
struct employee *insertfront(struct employee *head,struct employee *newemployee)
{
    if(head==NULL){
        return newemployee;}
        newemployee->next=head;
        head->prev=newemployee;
        return newemployee;
}
struct employee *deleteend(struct employee *head)
{
    if(head==NULL)
    {
        printf("List is empty cannot delete");
        return head;
    }
    if(head->next==NULL){
        free(head);
        return NULL;
    }
     struct employee *current=head;
     while(current->next->next!=NULL)
     {
         current=current->next;
     }
     free(current->next);
     return head;
}
struct employee *deletefront(struct employee *head)
{
    if(head==NULL)
    {
        printf("List is empty cannot delete");
        return head;
    }
    if(head->next==NULL){
        free(head);
        return NULL;
    }
    struct employee *newhead=head->next;
    head=head->next;
    free(head);
    return newhead;
}
void displayandcount(struct employee *head)
{
    struct employee *current=head;
    int count;
    printf("\n\nEmployee's details\n");
    printf("\n------------------------------------------------------------------------------\n");
    printf("SSN\t\tName\t\tDept\t\tDesignation\t\tSal\\tPhnp\n");
    printf("\n------------------------------------------------------------------------------\n");
    while(current!=NULL)
    {
        printf("%s\t\t%s\t\t%s\t\t%s\t\t%.2lf\t\t%s\n",current->SSN,current->name,current->dept,current->designation,current->sal,current->phno);
        current=current->next;
        count++;
    }
    printf("\nTotal employees:%d",count);
}
int main()
{
    struct employee *head=NULL;
    int choice;
    while(1)
    {
        printf("\n\nDoubly linked list menu\n");
        printf("1.Create an employee\n");
        printf("2.Insert at end\n");
        printf("3.Insert at front\n");
        printf("4.Delete at end\n");
        printf("5.Delete at front\n");
        printf("6.Display and count\n");
        printf("7.exit\n");
        printf("enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:{
            char SSN[20],name[20],dept[20],designation[20],phno[15];
            double sal;
            printf("Enter SSN:");
            scanf("%s",SSN);
            printf("Enter name:");
            scanf("%s",name);
            printf("Enter dept:");
            scanf("%s",dept);
            printf("Enter designation");
            scanf("%s",designation);
            printf("Enter salary:");
            scanf("%lf",&sal);
            printf("Enter phno:");
            scanf("%s",phno);
            struct employee *newemployee=createemployee(SSN,name,dept,designation,sal,phno);
            head=insertend(head,newemployee);
            break;
        }
         case 2:{
            char SSN[20],name[20],dept[20],designation[20],phno[15];
            double sal;
            printf("Enter SSN:");
            scanf("%s",SSN);
            printf("Enter name:");
            scanf("%s",name);
            printf("Enter dept:");
            scanf("%s",dept);
            printf("Enter designation");
            scanf("%s",designation);
            printf("Enter salary:");
            scanf("%.lf",&sal);
            printf("Enter phno:");
            scanf("%s",phno);
            struct employee *newemployee=createemployee(SSN,name,dept,designation,sal,phno);
            head=insertend(head,newemployee);
            break;
        }
         case 3:{
            char SSN[20],name[20],dept[20],designation[20],phno[15];
            double sal;
            printf("Enter SSN:");
            scanf("%s",SSN);
            printf("Enter name:");
            scanf("%s",name);
            printf("Enter dept:");
            scanf("%s",dept);
            printf("Enter designation");
            scanf("%s",designation);
            printf("Enter salary:");
            scanf("%.lf",&sal);
            printf("Enter phno:");
            scanf("%s",phno);
            struct employee *newemployee=createemployee(SSN,name,dept,designation,sal,phno);
            head=insertfront(head,newemployee);
            break;
        }
         case 4:
            head=deleteend(head);
            break;
         case 5:
            head=deletefront(head);
            break;
         case 6:
            displayandcount(head);
            break;
         case 7:
            exit(0);
         default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
