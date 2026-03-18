#include <stdio.h>

int subset_sum(int arr[], int n, int i, int current_sum, int target, int path[], int path_index) {

    if (current_sum == target) {
        printf("Selected tasks: ");
        for (int k = 0; k < path_index; k++) {
            printf("%d ", path[k]);
        }
        printf("\n");
        return 1;
    }

    if (i == n || current_sum > target) {
        return 0;
    }

    path[path_index] = arr[i];
    if (subset_sum(arr, n, i + 1, current_sum + arr[i], target, path, path_index + 1)) {
        return 1;
    }

    if (subset_sum(arr, n, i + 1, current_sum, target, path, path_index)) {
        return 1;
    }

    return 0;
}

int main() {
    int arr[] = {2, 3, 7};
    int n = 3;
    int target = 5;

    int path[n];

    if (!subset_sum(arr, n, 0, 0, target, path, 0)) {
        printf("No subset found\n");
    }

    return 0;
}
