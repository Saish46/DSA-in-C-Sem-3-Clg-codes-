#include <stdio.h>
#include <stdlib.h>

struct node 
{
  int data;
  struct node *next;
};

// Function 1 : create a linked list
struct node *create_list(int *count)
{
  struct node *head = 0, *temp = 0, *newNode = 0;
  int n, more;
  
  printf("How many nodes you want to insert initially - ");
  scanf("%d", &n);
  
  // Creating the initial nodes
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
    newNode->next = 0;
    
    if (head == 0)
    {
      head = newNode;
      temp = head;
    }
    else
    {
      temp->next = newNode;
      temp = newNode;
    }
    (*count)++;
  }
  
  // Insert a another node if user wants to insert
  while (1)
  {
    printf("Do you want to insert a another node? (1 for Yes / 0 for No) - ");
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
      newNode->next = 0;
      
      if (head == 0)
      {
        head = newNode;
        temp = head;
      }
      else
      {
        temp->next = newNode;
        temp = newNode;
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
  struct node *temp = head;
  
  printf("\nThe linked list is - \n");
  while (temp != 0)
  {
    printf("%d  ", temp->data);
    temp = temp->next;
  }
  printf("\n");
  
  printf("Total number of nodes - %d\n", count);
  printf("\n");
}

// Function 3 : Insert the node at user specified position
struct node *insert_at_position(struct node *head, int *count)
{
  struct node *temp;
  int pos, i = 1;
  
  printf("After which position you want to add new node - ");
  scanf("%d", &pos);
  
  if (pos > *count)
  {
    printf("Given position is invalid");
  }
  else
  {
    temp = head;
    while (i < pos)
    { 
      temp = temp->next;
      i++;
    }
    
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == 0)
    {
      printf("Memory not allocated\n");
      exit(1);
    }
    
    printf("Enter the data of new node at position %d - ", pos+1);
    scanf("%d", &newNode->data);
    
    newNode->next = temp->next;
    temp->next = newNode;
    
    (*count)++;
  }
  return head;
}

void main()
{
  struct node *head = 0;
  int count = 0;
  
  // Create a linked list
  head = create_list(&count);
  
  // Print the linked list
  print_list(head, count);
  
  // Inserting a new node at user specified position  
  head = insert_at_position(head, &count);
  
  // Printing the newly created linked list
  print_list(head, count);
}
      
      
      
      
      
      
      
      
      
      
      
      
    
  
  
  
  
  
  
  
  
  
  
  
  
