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
  
  printf("how many nodes you want to insert initially - ");
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
  
  // Create a node if user wants
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
  
  printf("The total number of nodes is - %d\n", count);
  
  printf("\n");
}

// Function 3 : delete a node from the beginning of the list
struct node *delete_from_beg(struct node *head, int *count)
{
  if(head == 0)
  {
    printf("Linked list is empty");
  }
  else
  {
    struct node *temp;
    temp = head;
    head = temp->next;
    free(temp);
    (*count)--;
  }
  return head;
}

void main()
{
  struct node *head = 0;
  int count = 0;
  
  // Create a linked list
  head = create_list(&count);
  
  // print the linked list
  print_list(head, count);
  
  // Deleting the node from the beginning of the list
  head = delete_from_beg(head, &count);

  printf("After the node delete from the beginning of the linked list - \n");
  
  // Printing the newly created list
  print_list(head, count);
}
  
