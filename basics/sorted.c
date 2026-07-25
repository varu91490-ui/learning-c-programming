#include<stdio.h>
int main()
{
int arr[10],n,i,k,j,asc=1,dsc=1;
printf("Enter the number of inputs");
scanf("%d",&n);
printf("Enter the input array:");
for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
for(i=0;i<n-1;i++){
if(arr[i]<arr[i+1]){
dsc=0;
}
if(arr[i]>arr[i+1]){
asc=0;
}
}
if(asc==1){
    printf("Array is sorted in asc");
}
else if(dsc==1){
    printf("Array is sorted in descending");
}
else{
    printf("Array is not sorted");
}
return 0;
}
