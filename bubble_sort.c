#include <stdio.h>

void get_array(int arr[], int *n)                             // Function to get the values of array from the user and store it 
{

  printf("Enter the number of elements - ");
  scanf("%d", n);
  
  printf("Enter the %d elements - \n", *n);
  for (int i = 0; i < *n; i++)
  {
    scanf("%d", &arr[i]);
  }
}

void bubble_sort(int arr[], int n)                           // Function to perform bubble sorting
{
  int temp, flag;
  for (int i = 0; i < n - 1; i++)                          // Here we write n - 1 in condition because total passes is equal to total elements - 1
  {
    flag = 0;                                              // To avoid unnecessary passes
    
    for (int j = 0; j < n - 1 - i; j++)                    // Here we write additional -i because to avoid unnecessary steps in passes,
    {                                                     // Whenever we go forward in passes there 1 unnecessary step will increase  
      if (arr[j] > arr[j + 1])
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        flag = 1;                                         // To know the swapping was done or not, to avoid unnecessary passes
      }
    }
    if (flag == 0)                                        // If this condition goes true means swapping was not done in last pass so, entire loop will be break
    {
      break;
    }
  }
}

void print_array(int arr[], int n)                        // Function to print the final sorted array
{
  printf("Final sorted array is - \n");     
  for (int i = 0; i < n; i++)
  {
    printf("%d  ", arr[i]);
  }
}

void main()
{ 
  int arr[100], n;
  
  get_array(arr, &n);                                    // Call the function to get values of array from the user and save it 
  
  bubble_sort(arr, n);                                   // Call the function to get sorted array
  
  print_array(arr, n);                                   // Call the function to print the final sorted array
}
