#include<stdio.h>
void towers(int,char,char,char);
int main()
{
    int num;
    printf("Enter thenumber of disks:\n");
    scanf("%d",&num);
    printf("The sequential moves involved in tower of hanoi are:\n");
    towers(num,'A','c','B');
    return 0;
}
void towers(int num,char frompeg,char topeg,char auxpeg)
{
    if(num==1)
    {
        printf("move disk 1 frpm peg %c to peg %c\n",frompeg,topeg);
        return;
    }
    towers(num-1,frompeg,auxpeg,topeg);
    printf("\nMove disk %d from peg %c to peg %c\n",num,frompeg,topeg);
    towers(num-1,auxpeg,topeg,frompeg);
}
