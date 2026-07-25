#include<stdio.h>
int main()
{
int arr[10],n,i,k,j;
printf("Enter the number of inputs");
scanf("%d",&n);
printf("Enter the input array:");
for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
int max=arr[0],secmax=arr[1];
if(secmax>max){
    int temp=max;
    max=secmax;
    secmax=temp;
}
for(i=2;i<n;i++){
        if(arr[i]>max){
            secmax=max;
            max=arr[i];
        }
        else if(arr[i]>secmax)
        {
            secmax=arr[i];
        }
    }
printf("The second largest element is %d",secmax);
return 0;
}
