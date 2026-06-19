#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Day{
char *dayname;
int date,month,year;
char *activity;
};
struct Day *createcalendar(int numdays)
{
    struct Day *calendar=(struct Day*)malloc(numdays*sizeof(struct Day));
    if(calendar==NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for(int i=0;i<numdays;i++){
    calendar[i].dayname=(char*)malloc(20*sizeof(char));
    calendar[i].activity=(char*)malloc(100*sizeof(char));
    }
    return calendar;
}
void readDay(struct Day *day)
{
    printf("Enter day name:");
    scanf("%s",day->dayname);
    printf("Enter date:");
    scanf("%d/%d/%d",&(day->date),&(day->month),&(day->year));
    printf("Enter activity:");
    scanf(" %[^\n]",day->activity);
}
void displayCalendar(struct Day *calendar,int numdays)
{
    printf("\nWeek's activity details:\n");
    for(int i=0;i<numdays;i++){
    printf("Day:%s\n",calendar[i].dayname);
    printf("Date:%d/%d/%d\n",calendar[i].date,calendar[i].month,calendar[i].year);
    printf("Activity:%s\n",calendar[i].activity);
    printf("\n");
    }
}
int main()
{
    int numdays;
    printf("Enter the number of days:");
    scanf("%d",&numdays);
    struct Day *calendar=createcalendar(numdays);
    for(int i=0;i<numdays;i++)
    {
        printf("Enter details of day %d:\n",i+1);
        readDay(&calendar[i]);
    }
    displayCalendar(calendar,numdays);
    for(int i=0;i<numdays;i++)
    {
        free(calendar[i].dayname);
        free(calendar[i].activity);
    }
    free(calendar);
    return 0;
}
