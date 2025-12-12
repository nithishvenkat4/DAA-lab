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
            if(arr[j] > arr[j+1]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Sorted Array By Bubble Sort");
    display(arr,n);
}

//SELECTION SORT
void selection_sort(int arr[],int n){
    int min,temp;

    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    printf("Sorted Array By Selection Sort");
    display(arr,n);
}

//INSERTION SORT
void insertion_sort(int arr[], int n){
    int key, j;
    for(int i=1;i<n;i++){
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    printf("Sorted Array By Insertion Sort");
    display(arr,n);
}

//MERGE FUNCTION (used by merge sort)
void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int a[n1], b[n2];

    for(int i=0;i<n1;i++) a[i] = arr[left + i];
    for(int j=0;j<n2;j++) b[j] = arr[mid + 1 + j];

    int i=0, j=0, k=left;

    while(i < n1 && j < n2){
        if(a[i] <= b[j]){
            arr[k++] = a[i++];
        }else{
            arr[k++] = b[j++];
        }
    }

    while(i < n1) arr[k++] = a[i++];
    while(j < n2) arr[k++] = b[j++];
}

//MERGE SORT
void merge_sort(int arr[], int left, int right){
    if(left < right){
        int mid = (left + right)/2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

//QUICK SORT PARTITION
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    int temp;

    for(int j=low; j<high; j++){
        if(arr[j] < pivot){
            i++;
            temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
        }
    }
    temp = arr[i+1]; arr[i+1] = arr[high]; arr[high] = temp;
    return i+1;
}

//QUICK SORT
void quick_sort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi+1, high);
    }
}

int main(){
    int n;
    printf("Enter the Array Size: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter Array Elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("Unsorted Array");
    display(arr,n);

    //sorting Function Calls
    bubble_sort(arr,n);
    selection_sort(arr,n);

    // insertion sort
    insertion_sort(arr,n);

    // merge sort
    merge_sort(arr, 0, n-1);
    printf("Sorted Array By Merge Sort");
    display(arr,n);

    // quick sort
    quick_sort(arr, 0, n-1);
    printf("Sorted Array By Quick Sort");
    display(arr,n);

    return 0;
}

