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
  
  printf("How many nodes you want to add initially - ");
  scanf("%d", &n);
  
  // create initial nodes
  for (int i = 0; i < n; i++)
  {
    newNode = (struct node *)malloc(sizeof(struct node *));
    if (newNode == 0)
    {
      printf("Memory not allocated\n");
      exit(1);
    }
    
    printf("Enter the data of the node %d - ", i+1);
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
  
  // Ask if user wants to add more nodes
  while (1)
  {
    printf("Do you want to add another node (1 for Yes / 0 for No) - ");
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
  
  printf("\nThe Linked List is - ");
  while (temp != 0)
  {
    printf("%d  ", temp->data);
    temp = temp->next;
  }
  printf("\n");
  
  printf("Total number of nodes - %d\n", count);
  printf("\n");
}

// Function 3 : insert node at beginning
struct node *insert_at_beginning(struct node *head, int *count)
{
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  if (newNode == 0)
  {
    printf("Memory not allocated\n");
    exit(1);
  }
  
  printf("Enter the data of new node at the beginning - ");
  scanf("%d", &newNode->data);
  
  newNode->next = head;
  head = newNode;
  
  (*count)++;
  
  return head;
}

void main()
{
  struct node *head;
  int count = 0;
  
  // Function 1 : create list
  head = create_list(&count);
  
  // Function 2 : print list
  print_list(head, count);
  
  // function 3 : insert node at beginning
  head = insert_at_beginning(head, &count);
  
  //function 2 : print new list
  print_list(head, count);
}

  
      
