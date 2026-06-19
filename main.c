#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Day{
char *dayname;
int date,month,year;
char *activity;
};
struct Day* createcalendar(int numdays){
struct Day* calendar=(struct Day*)malloc(numdays*sizeof(struct Day));
if(calendar==NULL){
    printf("memory allocation failed\n");
    exit(1);
}
for(int i=0;i<numdays;i++){
    calendar[i].dayname=(char*)malloc(20*sizeof(char));
    calendar[i].activity=(char*)malloc(100*sizeof(char));
}
return calendar;
}
void readDay(struct Day* Day){
printf("Enter day name:\n");
scanf("%s",Day->dayname);
printf("Enter date:\n");
scanf("%d/%d/%d",&(Day->date),&(Day->month),&(Day->year));
printf("Enter activity discription:\n");
scanf(" %[^\n]",Day->activity);
}
void displaycalendar(struct Day* calendar,int numdays){
printf("Week's activity details\n");
for(int i=0;i<numdays;i++){
printf("Day:%s\n",claendar[i].dayname);
printf("Date:%d/%d/%d\n",calendar[i].date,calendar[i].month,calendar[i].year);
printf("Activity:%s\n",calendar[i].activity);
printf("\n");
}
}
int main(){
int numdays;
printf("Enter the number of days in the week:");
scanf("%d",numdays);
    struct Day* calendar=createcalendar(numdays);
    for(int i-0;i<numdays;i++){
        printf("Enter details for day %d\n",i+1);
        readDay(&calendar[i]);
    }
    displaycalendar(calendar,numdays);
for(int i=0;i<numdays;i++){
    free(Calendar[i].dayname);
    free(calendar[i].activity);
}
free(calendar);
return 0;
}

