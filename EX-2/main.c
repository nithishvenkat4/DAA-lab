#include <stdio.h>
#include <stdlib.h>

//Array Display Function
void display(int arr[],int n){
printf("\n");
for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
}
printf("\n");
}
//BUBBLE SORT
void bubble_sort(int arr[],int n){

int temp;
for(int i=0;i<n;i++){
    for(int j=0;j<n-1-i;j++){
        if(arr[j]>arr[j+1]){
            temp=arr[j+1];
            arr[j+1]=arr[j];
            arr[j]=temp;
        }
    }
}
printf("Sorted Array By Bubble Array");
display(arr,n);
}

//Selection Sort
void selection_sort(int arr[],int n){

int min,temp;

for(int i=0;i<n-1;i++){
    min=i;
    for(int j=i+1;j<n;j++)
    {if(arr[j]<arr[min]){min=j;}}
    temp=arr[i];
    arr[i]=arr[min];
    arr[min]=temp;
}
printf("Sorted Array By Selection Sort");
display(arr,n);
}

int main()
{
    int n;
    printf("Enter the Array Size:");
    scanf("%d",&n);
    int arr[n];

    printf("Enter Array Elements ");
    for(int i=0;i<n;i++)
    {scanf("%d",&arr[i]);}

    printf("Unsorted Array");
    display(arr,n);
    //sorting Function Calls
    bubble_sort(arr,n);
    selection_sort(arr,n);

    return 0;
}
