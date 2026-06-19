#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student{
char USN[20];
char name[20];
char programme[30];
int sem;
char phno[15];
struct student *next;
};
struct student *createstudent(char USN[],char name[],char programme[],int sem,char phno[])
{
    struct student *newstudent=(struct student*)malloc(sizeof(struct student));
    if(newstudent==NULL){
        printf("Memory allocation failed\n");
    exit(1);
}
strcpy(newstudent->USN,USN);
strcpy(newstudent->name,name);
strcpy(newstudent->programme,programme);
newstudent->sem,sem;
strcpy(newstudent->phno,phno);
newstudent->next=NULL;
return newstudent;
}
struct student *insertfront(struct student *head,struct student *newstudent)
{
    newstudent->next=head;
    return newstudent;
}
struct student *insertend(struct student *head,struct student *newstudent)
{
    if(head==NULL){
        return newstudent;
    }
    struct student *current=head;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next=newstudent;
    return head;
}
struct student *deletefront(struct student *head)
{
    if(head==NULL)
        printf("List is empty cannot delete\n");
    struct student *temp=head;
    head=head->next;
    free(temp);
    return head;
}
void displayandcount(struct student *head)
{
    struct student *current=head;
    int count=0;
    printf("\nStudent details:\n");
    printf("\n-------------------------------------------------------------------------------\n");
    printf("USN\t\tName\t\tProgramme\t\tsem\t\tphno\n");
    printf("\n-------------------------------------------------------------------------------\n");
    while(current!=NULL)
    {
        printf("%s\t%s\t\t%s\t\t\t%d\t\t%s\n",current->USN,current->name,current->programme,current->sem,current->phno);
        current=current->next;
        count++;
    }
    printf("Total students is:%d",count);
}
int main()
{
    struct student *head=NULL;
    int choice;
    while(1)
    {
        printf("\nSingly linked list Menu\n");
        printf("1.create a student\n");
        printf("2.Insert at front\n");
        printf("3.Insert at end\n");
        printf("4.Delete at front\n");
        printf("5.Display and count\n");
        printf("6.exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:{
            char USN[20],name[20],programme[30],phno[15];
            int sem;
            printf("Enetr USN:");
            scanf("%s",USN);
            printf("Enetr Name:");
            scanf("%s",name);
            printf("Enetr programme:");
            scanf("%s",programme);
            printf("Enetr sem:");
            scanf("%d",&sem);
            printf("Enetr phno:");
            scanf("%s",phno);
            struct student *newstudent=createstudent(USN,name,programme,sem,phno);
            head=insertfront(head,newstudent);
            break;
        }
         case 2:{
            char USN[20],name[20],programme[30],phno[15];
            int sem;
            printf("Enetr USN:");
            scanf("%s",USN);
            printf("Enetr Name:");
            scanf("%s",name);
            printf("Enetr programme:");
            scanf("%s",programme);
            printf("Enetr sem:");
            scanf("%d",&sem);
            printf("Enetr phno:");
            scanf("%s",phno);
            struct student *newstudent=createstudent(USN,name,programme,sem,phno);
            head=insertfront(head,newstudent);
            break;
        }
         case 3:{
            char USN[20],name[20],programme[30],phno[15];
            int sem;
            printf("Enetr USN:");
            scanf("%s",USN);
            printf("Enetr Name:");
            scanf("%s",name);
            printf("Enetr programme:");
            scanf("%s",programme);
            printf("Enetr sem:");
            scanf("%d",&sem);
            printf("Enetr phno:");
            scanf("%s",phno);
            struct student *newstudent=createstudent(USN,name,programme,sem,phno);
            head=insertend(head,newstudent);
            break;
        }
         case 4:
            head=deletefront(head);
            break;
         case 5:
            displayandcount(head);
            break;
         case 6:
            exit(0);
         default:
            printf("Invslid choice\n");
        }
    }
    return 0;
}
