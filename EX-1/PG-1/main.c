#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//regular iterative linear search
int linear_search(int n,int target,int arr[]){

    for(int i=0;i<n;i++){
        if(target==arr[i]){
            return i;
        }
    }
    return -1;
}

//recursive linear search
int linear_search_rec(int n,int target,int arr[],int i){

    if(i>=n){return -1;}

    if(arr[i]==target){
        return i;
    }
    else{
        i++;
        return linear_search_rec(n,target,arr,i);}

}

//regular iterative binary search
int binary_search(int arr[],int target,int n){

    int low=0;
    int high=n-1;
    int mid;

    while (low<=high){

        mid=(low+high)/2;
        if (arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            low=mid+1;
        }
        else{high=mid-1;}
   }
   return -1;
}

//recursive binary search
int binary_search_rec(int arr[],int target,int low,int high){

    if(low>high){ return -1;}
    int mid=(low+high)/2;

    if (arr[mid]==target){
        return mid;
    }
    else if(arr[mid]<target){
        low=mid+1;
        return binary_search_rec(arr,target,low,high);
    }
    else{
        high=mid-1;
        return binary_search_rec(arr,target,low,high);
    }
    return -1;
}

//bubble sort for binary with binary calls
void bubble_sort(int n ,int arr[],int target){

    for (int i=0;i<n;i++){
        for (int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("\n\n  Sorted Array \n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }

    //interative binary search begins
    printf("\n\n Search by Iterative Binary Search :");

    //time calculation
    clock_t start_bsi = clock();
    int solution1=binary_search(arr,target,n);
    clock_t end_bsi = clock();

    double time_bsi = (double)(end_bsi-start_bsi)/CLOCKS_PER_SEC;
    printf("\nTime Taken By Iterative Binary Search is %f",time_bsi);

    if(solution1>=0){
        printf("\nTarget Found at Index %d",solution1);}
    else{printf("\nTarget Not Found");}

    //interative binary search ends

    //recursive binary search begins
    printf("\n Search by Recursive Binary Search :");
    //time calculation
    clock_t start_bsr = clock();
    int solution2=binary_search_rec(arr,target,0,n-1);  
    clock_t end_bsr = clock();

    double time_bsr = (double)(end_bsr-start_bsr)/CLOCKS_PER_SEC;
    printf("\nTime Taken By Recursive Binary Search is %f",time_bsr);

    if(solution2>=0){
        printf("\nTarget Found at Index %d",solution2);}
    else{printf("\nTarget Not Found");}

    //recursive binary search ends

}

int main()
{
    int n;
    printf("Enter the array size:");
    scanf("%d",&n);
    int arr[n];

    printf("Enter Array Elements \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int target;
    printf("Enter the Target Value:");
    scanf("%d",&target);

    printf("\n Search by Iterative Linear Search :");

    //iterative linear search 
    //time cal
    clock_t start_lsi = clock();
    int solution1=linear_search(n,target,arr);
    clock_t end_lsi = clock();

    double time_lsi = (double)(end_lsi-start_lsi);
    printf("\n Time Taken By Iterative Linear Search is %f",time_lsi);

    if(solution1>=0){
        printf("\nTarget Found at Index %d",solution1);}
    else{printf("\nTarget Not Found");}

    //recursive linear search
    printf("\n\n Search by Recursive Linear Search :");

    //time cal
    clock_t start_lsr = clock();
    int solution2=linear_search_rec(n,target,arr,0);
    clock_t end_lsr = clock();

    
    double time_lsr = (double)(end_lsr-start_lsr);
    printf("\nTime Taken By Iterative Linear Search is %f",time_lsr);


    if(solution2>=0){
        printf("\nTarget Found at Index %d",solution2);}
    else{printf("\nTarget Not Found");}

    bubble_sort(n,arr,target);

    return 0;
}
