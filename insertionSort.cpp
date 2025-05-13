// C++ program for implementation of Insertion Sort
// Selection Sort

// Best case: O(n), If the list is already sorted, where n is the number of elements in the list.
// Average case: O(n2), If the list is randomly ordered
// Worst case: O(n2), If the list is in reverse order

/*
What are the Boundary Cases of the Insertion Sort algorithm?
-> Insertion sort takes the maximum time to sort if elements are sorted in reverse order. And it takes minimum time (Order of n) when elements are already sorted. 

What is the Algorithmic Paradigm of the Insertion Sort algorithm?
-> The Insertion Sort algorithm follows an incremental approach. 

Is Insertion Sort an in-place sorting algorithm?
-> Yes, insertion sort is an in-place sorting algorithm. 

Is Insertion Sort a stable algorithm?
-> Yes, insertion sort is a stable sorting algorithm. 

When is the Insertion Sort algorithm used?
-> Insertion sort is used when number of elements is small. It can also be useful when the input array is almost sorted, and only a few elements are misplaced in a complete big array. 
*/



#include <iostream>
using namespace std;


void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Driver method
int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<"Input Array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }    
    insertionSort(arr, n);
    cout<<"\nSorted Array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
