#include <stdio.h>

void get_array(int arr[], int *n, int *key)                          // Function to get values of array from user
{
  printf("Enter the number of elements - ");    
  scanf("%d", n);
  
  printf("Enter the %d elements - \n", *n);
  for (int i = 0; i < *n; i++)
  {
    scanf("%d", &arr[i]);                                         // Store the values of array which taken from the user
  }
  
  printf("Enter the element to search - ");   
  scanf("%d", key);
}

int linear_search(int arr[], int n, int key)                       // Function to perform linear search
{
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == key)
    {
      return i;                                                   // Means, element found and return the element's index value
    }
  }
  return -1;                                                      // Means, element not found
}

void print_index(int arr[], int n, int key)                         // Function to print index value of element which user wants to find
{
  int result = linear_search(arr, n, key);                         // Call the linear_search function to perform linear search and save it in result
  
  if (result != -1)
  {
    printf("Element %d is found at %dth position", key, result+1);
  }
  else
  {
    printf("Element %d is not found in array", key);
  }
}

void main()
{
  int arr[100], n, key;
  
  get_array(arr, &n, &key);                                         // Call the function to get arrays and other values from user and store it 
  
  print_index(arr, n, key);                                         // Call the Function to get final ans.
  
}
