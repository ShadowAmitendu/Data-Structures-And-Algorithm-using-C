#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int arr[], int len)
{
    int i = 0;
    bool swapped = false;
    do
    {
        swapped = false;
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        i++;
    } while (swapped);
}

void printArr(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d -> ", arr[i]);
    }
    printf("NULL\n");
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int len = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArr(arr, len);

    bubbleSort(arr, len);

    printf("Sorted array:\n");
    printArr(arr, len);

    return 0;
}