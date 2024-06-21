//WAP to sort array using Insertion Sort
#include <math.h>
#include <stdio.h>
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int a,arr[100];
    printf("Enter number of elements : ");
    scanf("%d",&a);
    printf("Enter numbers \n");
    for(int i=0;i<a;i++)
    scanf("%d",&arr[i]);
    printf("Sorted Array : \n");
    insertionSort(arr, a);
    printArray(arr, a);
    return 0;
}
