#include <stdio.h>

void selectionSort(int a[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int min_pos = i;
        for (int j = i + 1; j < length; j++)
        {
            if (a[j] < a[min_pos])
            {
                min_pos = j;
            }
        }
        // Swap the found minimum element with the first element
        if (min_pos != i)
        {
            int temp = a[i];
            a[i] = a[min_pos];
            a[min_pos] = temp;
        }
    }
}

void printArr(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int len = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArr(arr, len);

    selectionSort(arr, len);

    printf("Sorted array:\n");
    printArr(arr, len);

    return 0;
}
