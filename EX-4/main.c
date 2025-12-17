#include <stdio.h>
#include <stdlib.h>

void display(int val,char msg[]){
printf("%s Element is: %d  \n",msg,val);
}

void max_i(int arr[],int n){
int max=arr[0];
for (int i=1;i<n;i++){
    if(arr[i]>max){max=arr[i];}
}
display(max,"Iterative Max");
}

void max_r(int arr[] ,int n,int val,int count){
int max=val;
if (count==n){display(max,"Recursive Max");}
else{
    if(arr[count]>max){max=arr[count];}
    max_r(arr,n,max,count+1);
}
}

void min_i(int arr[],int n){
int min=arr[0];
for (int i=1;i<n;i++){
    if(arr[i]<min){min=arr[i];}
}
display(min,"Iterative Min");
}

void min_r(int arr[] ,int n,int val,int count){
int min=val;
if (count==n){display(min,"Recursive Min");}
else{
    if(arr[count]<min){min=arr[count];}
    min_r(arr,n,min,count+1);
}
}


int main()
{
    int n;
    printf("Enter Number of Elements in the Array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter Array Elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);}

    min_i(arr,n);
    min_r(arr,n,arr[0],0);
    max_i(arr,n);
    max_r(arr,n,arr[0],0);
    return 0;
}
