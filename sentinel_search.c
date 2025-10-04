#include <stdio.h>

// Function 1: Get array from user
void get_array(int arr[], int *n, int *key) 
{
    printf("Enter size of array: ");
    scanf("%d", n);

    printf("Enter %d elements: \n", *n);
    for (int i = 0; i < *n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter element to search: ");
    scanf("%d", key);
}

// Function 2: Perform Sentinel Search
int sentinel_search(int arr[], int n, int key) 
{
    int last = arr[n - 1];   // store last element
    arr[n - 1] = key;        // put key at last (sentinel)
    int i = 0;

    while (arr[i] != key) 
    {
        i++;
    }

    arr[n - 1] = last;       // restore last element

    if (i < n - 1 || arr[n - 1] == key)
    {
      return i;  // element found
    }
    else
    {
      return -1; // element not found
    }
}

// Function 3: Print the result
void print_index(int arr[], int n, int key) 
{
    int index = sentinel_search(arr, n, key);
    
    if (index == -1)
    {
        printf("Element not found in array.\n");
    }
    else
    {
        printf("Element found at index %d\n", index+1);
    }
}

void main() {
    int arr[50], n, key;

    get_array(arr, &n, &key);

    print_index(arr, n, key);
}
