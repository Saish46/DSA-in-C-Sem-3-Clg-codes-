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
  
  // Create initial node in linked list
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
      
      printf("Enter the data of the new node  - ");
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
  
  printf("\nThe linked list - \n");
  while (temp != 0)
  {
    printf("%d  ", temp->data);
    temp = temp->next;
  }
  printf("\n");
  
  printf("The total number of nodes is - %d\n", count);
  
  printf("\n");
}

// Function 3 : search a given element
void search_given_element(struct node *head)
{
  struct node *temp;
  temp = head;
  int element, flag = 0, i = 1;
  
  printf("Enter the element which you want to search - ");
  scanf("%d", &element);
  
  printf("\n");
  
  while (temp != 0)
  {
    if (temp->data == element)
    {
      printf("Given element is found at %dth position node\n", i);
      printf("\n");
      flag = 1;
    }
    temp = temp->next;
    i++;
  }
  if (flag == 0)
  {
    printf("Given element is not found in linked list\n");
    printf("\n");
  }
}

void main()
{
  struct node *head = 0;
  int count = 0;
  
  // Create a linked list
  head = create_list(&count);
  
  // Print the linked list
  print_list(head, count);
  
  // Searching the given element in linked list
  search_given_element(head);
}
    
