#include <stdio.h>
#include <stdlib.h>

struct node 
{
  int data;
  struct node *prev;
  struct node *next;
};

// Function 1 : create a linked list
struct node *create_list(int *count)
{
  struct node *head = 0, *temp = 0, *newNode = 0;
  int n, more;
  
  printf("Enter the number of nodes you wants to insert - ");
  scanf("%d", &n);
  
  // Creating initial nodes
  for (int i = 0; i < n; i++)
  {
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == 0)
    {
      printf("Memory not allocated\n");
      exit(1);
    }
    
    printf("Enter the data of node %d - ", i+1);
    scanf("%d", &newNode->data);
    newNode->prev = 0;
    newNode->next = 0;
    
    if (head == 0)
    {
      head = newNode;
      temp = head;
    }
    else
    {
      temp->next = newNode;
      newNode->prev = temp;
      temp = newNode;
    }
    (*count)++;
  }
  
  // Creating a node if user wants to create
  while (1)
  {
    printf("Do you wants to insert a another node? (1 for Yes / 0 for No) - ");
    scanf("%d", &more);
    
    if (more == 1)
    {
      newNode = (struct node *)malloc(sizeof(struct node));
      if (newNode == 0)
      {
        printf("Memory not allocated\n");
        exit(1);
      }
      
      printf("Enter the data of the new node - ");
      scanf("%d", &newNode->data);
      newNode->prev = 0;
      newNode->next = 0;
      
      if (head == 0)
      {
        head = newNode;
        temp = head;
      }
      else
      {
        temp->next = newNode;
        newNode->prev = temp;
      }
      (*count)++;
    }
    else
    {
      break;
    }
  }
  return head;
}

// Function 2 : print the linked list
void print_list(struct node *head, int count)
{
  struct node *temp;
  temp = head;
  
  printf("\nThe linked list is - \n");
  while (temp != 0)
  {
    printf("%d  ", temp->data);
    temp = temp->next;
  }
  printf("\n");
  
  printf("The total number of nodes is - %d\n", count);
  
  printf("\n");
}

// Function 3 : inserting a node at the end of the linked list
struct node *insert_at_end(struct node *head, int *count)
{
  struct node *temp, *newNode = 0;
  temp = head;
  
  newNode = (struct node *)malloc(sizeof(struct node));
  if (newNode == 0)
  {
    printf("Memory not allocated\n");
    exit(1);
  }
  
  printf("Enter the data of the new node which you wants to insert at end - ");
  scanf("%d", &newNode->data);
  newNode->next = 0;
  
  while (temp->next != 0 )
  {
    temp = temp->next;
  }
  temp->next = newNode;
  newNode->prev = temp;
  
  (*count)++;
  return head;
}

void main()
{
  struct node *head = 0;
  int count = 0;
  
  // Create a linked list
  head = create_list(&count);
  
  // Print a linked list
  print_list(head, count);
  
  // Insert a node at end of the linked list
  head = insert_at_end(head, &count);
  
  // Printing the newly created linked list
  print_list(head, count);
}
