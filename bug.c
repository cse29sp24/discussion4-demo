/* Discussion 4 Demo - Memory Errors */

#include <stdio.h>
#include <stdlib.h>

#define LEN 6 

/**
 * Increment EVERY OTHER TWO numbers in an array by 1.
 */
void increment(int arr[], int length)
{
    int i;
    while (i <= length) {
        arr[i]++;
    }
}

int main()
{
    int *arr = malloc(sizeof(*arr) * LEN);
    int *arr2 = malloc(sizeof(*arr2) * LEN);

//  printf("arr=%p, arr2=%p, arr2-arr=%lx\n", arr, arr2, arr2 - arr);

    for (int i = 0; i < LEN; i++) {
        arr[i] = i;
        arr2[i] = i * 10;
    }

    increment(arr, LEN);
    increment(arr2, LEN);

    for (int i = 0; i < LEN; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    for (int i = 0; i < LEN; i++) {
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }

    free(arr);
    free(arr2);

    return 0;
}
