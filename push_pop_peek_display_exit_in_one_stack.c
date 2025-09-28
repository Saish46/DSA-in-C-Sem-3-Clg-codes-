#include <stdio.h>
#include <stdlib.h>

// Structure of stack (using array)
#define SIZE 10

int stack[SIZE];
int top = -1;

// Function 1 : To perform Push, means add an element to the top of stack
void push()
{
  int n, data;
  printf("How Many numbers you wants to add in stack? - ");
  scanf("%d", &n);
  
  if (n <= SIZE)
  {
    for (int i = 0; i < n; i++)
    {
      printf("Enter the data - ");
      scanf("%d", &data);
  
      top++;
      stack[top] = data;
    }
    printf("\n");
  }
  else
  {
    printf("Enter the valid number\n");
  }
}

// Function 2 : To perform Pop, means remove the top element from the stack
void pop()
{
  int element;
  
  if (top == -1)
  {
    printf("Stack is empty (Underflow)\n");
  }
  else
  {
    element = stack[top];
    top--;
    
    printf("Element '%d' is removed from stack\n", element);
    printf("\n");
  }
}

// Function 3 : To perform Peek/Top, means display the top element of the stack without removing it
void peek()
{
  if (top == -1)
  {
    printf("Stack is empty\n");
  }
  else
  {
    printf("The element at the top of stack is - %d\n", stack[top]);
  }
  printf("\n");
}

// Function 4 : To perform Display, means show all elements of stack
void display()
{
  if (top == -1)
  {
    printf("Stack is empty\n");
  }
  else
  {
    for (int i = top; i >= 0; i--)
    {
      printf("%d  ", stack[i]);
    }
    printf("\n");
  } 
  printf("\n");
}

// Function 5 : Do the operation in stack by user choice
void do_operation()
{
  int choice;
  
  while (1)
  {
    printf("         - Start Menu -         \n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek/Top\n");
    printf("4. Display\n");
    printf("5. Exit\n"); 
    printf("\n");
    printf("Enter the index number of operation from above menu which you want to do in stack - ");
    scanf("%d", &choice);
    printf("\n");
    
    switch (choice)
    {
      case 1 : push();
      break;
      case 2 : pop();
      break;
      case 3 : peek();
      break;
      case 4 : display();
      break;
      case 5 : exit(0);        // terminate the program
      default : printf("Enter the valid index number\n");
    }
  }
}
    
void main()
{
  // Doing operation in stack by choice of user
  do_operation();
}
