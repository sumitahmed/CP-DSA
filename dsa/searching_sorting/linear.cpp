#include <iostream>
#include <cstdio>

void linear_search(int *arr, int n, int item)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(arr[i] == item)
        {
            std::printf("Element found at index %d\n", i);
            return;   // stop function once found
        }
    }

    // if loop completes fully
    std::printf("Element not found\n");
}

int main()
{
    int n, i, item;

    std::printf("Size of array: ");
    std::scanf("%d", &n);

    int arr[n];

    std::printf("Elements of array:\n");
    for(i = 0; i < n; i++)
    {
        std::scanf("%d", &arr[i]);
    }

    std::printf("Enter the search element: ");
    std::scanf("%d", &item);

    linear_search(arr, n, item);
    return 0;
}
