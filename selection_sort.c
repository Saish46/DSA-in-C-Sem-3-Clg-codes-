#include <stdio.h>

void get_array(int arr[], int *n)                              // Function to get the values of array from the user and save it 
{
  printf("Enter the number of elements - ");
  scanf("%d", n);
  
  printf("Enter %d elements - \n", *n);
  for (int i = 0; i < *n; i++)
  {
    scanf("%d", &arr[i]);
  }
}

void selection_sort(int arr[], int n)                         // Function to perform selection sort
{
  int min, temp;
  for (int i = 0; i < n - 1; i++)                           // This 'for' loop for the passes
  {
    min = i;                                                // We store always 1st position value of unsorted sublist in min variable to compare
    for (int j = i + 1; j < n; j++)                         // This loop is use for compare the above 1st position element which is now store in min variable with remaining elements
    {
      if (arr[j] < arr[min])            
      {
        min = j;
      }
    }
    if (min != i)                                           // Above in starting of the first loop we mention that min = i, and here condition is min is not equals to i,
    {                                                       // means if ith position element is the smallest one in the array then this if loop not runs, but if its true then,
      temp = arr[i];                                        // this means there is another element which is smallest than ith position element so then this if loop will work  
      arr[i] = arr[min];                                   // and these 2 values will swap together
      arr[min] = temp;
    }
  }
}

void print_array(int arr[], int n)                           // Function to print the final sorted array
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
  
  get_array(arr, &n);                                       // Call the function to get values of array from the user and save it 
  
  selection_sort(arr, n);                                  // Call the function to get final sorted array
  
  print_array(arr, n);                                     // Calling the function to print final sorted array
  
}
