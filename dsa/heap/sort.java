// Write a prog 
// To perform heap sort
// To print elements of an array in descending order
// Time 20 min

import java.util.*;

class A{
    void heapify(int arr[], int n, int i) {
        int largest = i; // Initialize largest as root
        int l = 2 * i + 1; // left = 2*i + 1
        int r = 2 * i + 2; // right = 2*i + 2

        // If left child is larger than root
        if (l < n && arr[l] > arr[largest])
            largest = l;

        // If right child is larger than largest so far
        if (r < n && arr[r] > arr[largest])
            largest = r;

        // If largest is not root
        if (largest != i) {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;

            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }
    }

    void heapSort(int arr[], int n) {
        // Build heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        // One by one extract elements from heap
        for (int i = n - 1; i > 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            // call max heapify on the reduced heap
            heapify(arr, i, 0);
        }
    }

    void printArray(int arr[], int n) {
        for (int i = n - 1; i >= 0; i--)
            System.out.print(arr[i] + " ");
    }

    public static void main(String args[]) {
        A ob = new A();
        int arr[] = {12, 11, 13, 5, 6, 7};
        int n = arr.length;

        ob.heapSort(arr, n);

        System.out.println("Sorted array is");
        ob.printArray(arr, n);
    }
}