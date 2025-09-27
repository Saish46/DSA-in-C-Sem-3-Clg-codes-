#include <stdio.h>

void get_array(int arr[], int *n, int *key)                              // Function to get values of array from user
{
  printf("Enter the number of elements - ");
  scanf("%d", n);
  
  printf("Enter the %d sorted elements - \n", *n);
  for (int i = 0; i < *n; i++)
  {
    scanf("%d", &arr[i]);                                               // Store the values of array which taken from the user
  }
  
  printf("Enter the element to search - ");
  scanf("%d", key);
}

int binary_search(int arr[], int n, int key)                            // Function to perform binary search
{
  int low = 0, high = n-1, mid;
  
  while (low <= high)
  {
    mid = (low + high) / 2;
    
    if (arr[mid] == key)
    {
      return mid;                                                     // Means, element found and return the element's index value
    }
    else if (arr[mid] < key)
    {
      low = mid + 1;
    }
    else if (arr[mid] > key)
    {
      high = mid - 1;
    }
  }
  return -1;                                                           // Means, element not found
}

void print_index(int arr[], int n, int key)                            // Function to print index value of element which user wants to find
{
  int result = binary_search(arr, n, key);                           // Call the binary_search function to perform binary search and save it in result
  
  if (result != -1)
  {
    printf("Element %d is found at %dth position in array", key, result+1);
  }
  else
  {
    printf("The given element not found in array");
  }
}

void main()
{
  int arr[100], n, key;
  
  get_array(arr, &n, &key);                                         // Call the function to get values of array and other values from the user and store it 
  
  print_index(arr, n, key);                                         // Call the Function to get final ans.
}
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
