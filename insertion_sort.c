#include <stdio.h>

void get_array(int arr[], int *n)                           // Function to get values of array from the user and save it 
{
  printf("Enter the number of elements - ");
  scanf("%d", n);
  
  printf("Enter the %d elements - \n", *n);
  for (int i = 0; i < *n; i++)
  {
    scanf("%d", &arr[i]);
  }
}

void insertion_sort(int arr[], int n)                       // Function to perform the insertion sort
{
 int temp, j;     
 for (int i = 1; i < n; i++)                              // This for loop is for unsorted sublist
  {
    temp = arr[i];                                        // Here we always save the first element of unsorted sublist
    j = i - 1;                                            // Element's position of back most of first element of unsorted sublist, means position of first element of sorted sublist
    
    while (i >= 0 && arr[j] > temp)
    {
      arr[j + 1] = arr[j];                                // If 1st element of sorted sublist is greater than temp(1st element of unsorted sublist) and ith position is greater than 0 then,
      j--;                                                // Element which is on 1st position of the sorted sublist is store in 1st position of the unsorted sublist
    }
    arr[j + 1] = temp;
  }
}

void print_array(int arr[], int n)                         // Function to print the final sorted array
{
  printf("Your final sorted array is - \n");
  for (int i = 0; i < n; i++)
  {
    printf("%d  ", arr[i]);    
  }
}

void main()
{
  int arr[100], n;
  
  get_array(arr, &n);                                      // Calling the function to get values of array from the user and save it 
  
  insertion_sort(arr, n);                                  // Calling the function to get final sorted array
  
  print_array(arr, n);                                      // Calling the function to print final sorted array
}

