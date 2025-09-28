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
  
  printf("Enter the number of nodes you want to insert - ");
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
    
    printf("Enter the data of the node %d - ", i+1);
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
  
  // Create a another node if user wants to create
  while (1)
  {
    printf("Do you want insert a another node? (1 for yes / 0 for No) - ");
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
        temp->prev = temp;
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
  struct node *temp;
  temp = head;
  
  printf("\nThe Linked list - \n");
  while (temp != 0)
  {
    printf("%d  ", temp->data);
    temp = temp->next;
  }
  printf("\n");
  
  printf("The total number of nodes is - %d\n", count);
  
  printf("\n");
}

// Function 3 : Print linked list in reverse order
void print_list_reverse(struct node *head, int count)
{
  struct node *temp;
  temp = head;
  
  printf("\nThe linked list in reverse order - \n");
  
  // First Saving the address of last node in temp
  while (temp->next != 0)
  {
    temp = temp->next;
  }
  // travel from last node to first node of list with printing each node element  
  while (temp != 0)
  {
    printf("%d  ", temp->data);
    temp = temp->prev;
  }
  
  printf("\n");
  
  printf("The total number of node is - %d\n", count);
  
  printf("\n");
}
  
void main()
{
  struct node *head = 0;
  int count = 0;
  
  // Creating the linked list
  head = create_list(&count);
  
  // Printing the linked list
  print_list(head, count);
  
  // Printing the linked list in reverse list 
  print_list_reverse(head, count);
}
