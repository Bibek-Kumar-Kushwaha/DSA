//WAP to sort array using Selection Sort
#include <stdio.h>
int main()
{
     int a[100], n, c;

    printf("Enter number of elements : ");
    scanf("%d", &n);
    printf("Enter %d integers \n", n);
    for (c = 0; c < n; c++)
        scanf("%d", &a[c]);
    int min_index;
    for(int i = 0; i < n - 1; i++) {
        min_index = i;
        for(int j = i + 1; j < n; j++) {
            if(a[min_index] > a[j]) {
                min_index = j;
            }
        }
        if(min_index != i)
        {
            int temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
        }
    }
    printf("Sorted Array: ");
    for(int i = 0; i < n; i++)  {
        printf(" %d", a[i]);
    }
    return 0;
}
