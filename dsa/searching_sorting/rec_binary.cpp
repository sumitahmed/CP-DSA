#include <iostream>
using namespace std;

int r_binary_search(int arr[], int beg, int end, int item) {
    if (beg <= end) {
        int mid = (beg + end) / 2;

        if (arr[mid] == item)
            return mid;
        else if (item < arr[mid])
            return r_binary_search(arr, beg, mid - 1, item);
        else
            return r_binary_search(arr, mid + 1, end, item);
    }
    return -1;
}

int main() {
    int arr[] = {7, 9, 12, 13, 18, 21};
    int n = 6;
    int item = 18;

    int index = r_binary_search(arr, 0, n - 1, item);

    if (index != -1)
        cout << "Item found at index " << index;
    else
        cout << "Item not found";

    return 0;
}
