#include <iostream>
#include <cstdio>

void binary_search(int *arr, int n, int item)
{
    int mid, beg =0, end = n-1;
    while(beg<=end){
        mid=(beg+end)/2;
        if(arr[mid]=item)
        {
            std::printf("%d", mid);
            break;
        }
        else if(arr[mid]>item){
            end = mid -1;
        }
        else{ // 
            beg= mid+1;
        }
    }
    if(beg>end){
        std::printf("item not found");
    }
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

    binary_search(arr, n, item);
    return 0;
}
