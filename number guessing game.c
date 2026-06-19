#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
printf("hello buddy this is a number guessing game try ur luck!!*~*");
srand(time(0));//without this rand generates same number everytime
int a=rand()%100+1;
int guess;
while(1){
printf("\nEnter your guess:");
scanf("%d",&guess);
    if(guess<a){
        printf("too low the number was %d",a);}
    else if(guess>a){
        printf("too high the number is less than the number u guessed buddy the number was %d",a);}
    else{
        printf("perfect");
            break;
    }
}
}
