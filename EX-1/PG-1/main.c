#include <stdio.h>
#include <stdlib.h>

int linear_search(int n,int target,int arr[]){

    for(int i=0;i<n;i++){
        if(target==arr[i]){
            return i;
        }
    }
    return -1;
}

int linear_search_rec(int n,int target,int arr[],int i){

    if(i>=n){return -1;}

    if(arr[i]==target){
        return i;
    }
    else{
        i++;
        return linear_search_rec(n,target,arr,i);}

}

void bubble_sort(int n ,int arr[]){

    for (int i=0;i<n;i++){
        for (int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("\n%d ",arr[i]);
    }

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
    int solution1=linear_search(n,target,arr);

    if(solution1>=0){
        printf("Target Found at Index %d",solution1);}
    else{printf("Target Not Found");}

    printf("\n Search by Recursive Linear Search :");
    int solution2=linear_search_rec(n,target,arr,0);

    if(solution2>=0){
        printf("Target Found at Index %d",solution2);}
    else{printf("Target Not Found");}

    bubble_sort(n,arr);



    return 0;
}
