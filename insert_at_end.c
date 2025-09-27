#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

// Function 1 : create the linked list
struct node *create_list(int *count)
{
  struct node *head = 0, *temp = 0, *newNode = 0;
  int n, more;
  
  printf("how many nodes you want to add initially - ");
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
  
  // Create nodes if user wants to create another nodes
  while (1)
  {
    printf("Do you want to add a new node (1 for Yes / 0 for No) - ");
    scanf("%d", &more);
    
    if (more == 1)
    {
      newNode = (struct node *)malloc(sizeof(struct node));
      if (newNode == 0)
      {
        printf("Memory not allocated\n");
        exit(1);
      }
      
      printf("Enter the data of new node - ");
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

// Function 2 : printing the linked list
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

// Function 3 : insert the new node at the end of the linked list
struct node *insert_at_end(struct node *head, int *count)
{
  struct node *temp = 0;
  
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  if (newNode == 0)
  {
    printf("Memory not allocated\n");
    exit(1);
  }
  
  printf("Enter the data of new node at end - ");
  scanf("%d", &newNode->data);
  
  newNode->next = 0;
  temp = head;
  
  while (temp->next != 0)
  {
    temp = temp->next;
  }
  temp->next = newNode;
  
  (*count)++;
  
  return head;
}

void main()
{
  struct node *head = 0;
  int count = 0;
  
  // Create linked list
  head = create_list(&count);
  
  // Print the linked list
  print_list(head, count);
  
  // Insert the new node at the end of linked list
  head = insert_at_end(head, &count);
  
  // Print the newly created list
  print_list(head, count);
  
}
  
