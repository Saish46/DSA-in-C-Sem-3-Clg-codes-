#include <stdio.h>
#include <stdlib.h>

#define SIZE 10   // size of queue
int queue[SIZE];
int front = -1, rear = -1;

// Function 1: Enqueue, inserting an element at the rear
void enqueue() 
{
    int n, value;
    printf("How many values you want to insert ? - ");
    scanf("%d", &n);
    
    if (n <= SIZE)
    {
      for (int i = 0; i < n; i++) 
      {
          if (rear == SIZE - 1) 
          {
              printf("Queue is Full! Cannot insert more values.\n");
              break;
          } 
          else 
          {
              printf("Enter value %d: ", i + 1);
              scanf("%d", &value);
              if (front == -1) 
              {
                front = 0; // for first element
              }
              rear++;
              queue[rear] = value;
              printf("%d inserted into the queue.\n", value);
          }
      }
    }
    else
    {
      printf("Enter the valid number\n");
    }
}

// Function 2: Dequeue, delete an element from the front
void dequeue() 
{
    if (front == -1 || front > rear) 
    {
        printf("Queue is Empty!\n");
    } 
    else 
    {
        printf("%d dequeued from the queue.\n", queue[front]);
        front++;
    }
}

// Function 3: peek, display the element at the front without removing it
void peek() 
{
    if (front == -1 || front > rear) 
    {
        printf("Queue is Empty!\n");
    } 
    else 
    {
        printf("Front element is: %d\n", queue[front]);
    }
}

// Function 4: Display, means displaying all the element of queue
void display() 
{
    if (front == -1 || front > rear) 
    {
        printf("Queue is Empty!\n");
    } 
    else 
    {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) 
        {
            printf("%d  ", queue[i]);
        }
        printf("\n");
    }
}

// Function 5 : function to perform operation on queue by user's choice
void do_operations() 
{
    int choice;
    while (1) 
    {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) 
        {
            case 1: enqueue(); 
            break;
            case 2: dequeue(); 
            break;
            case 3: peek(); 
            break;
            case 4: display(); 
            break;
            case 5: exit(0);              // Terminate the program
            default: printf("Invalid choice! Try again.\n");
        }
    }
}

void main() 
{
    
    // Function to perform operation on queue by user's choice
    do_operations();
}
