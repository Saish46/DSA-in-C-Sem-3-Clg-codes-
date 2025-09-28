#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

// Function 1: Create linked list from user input
struct Node *createList(int *count) 
{
    struct Node *head = 0, *temp = 0, *newNode = 0;
    int n, more;

    printf("How many nodes you want to add initially: ");
    scanf("%d", &n);

    // Create initial nodes
    for (int i = 0; i < n; i++) 
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == 0) 
        {
            printf("Memory not allocated.\n");
            exit(1);
        }
        printf("Enter data for node %d: ", i + 1);
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
        printf("Do you want to add another node? (1 for Yes / 0 for No): ");
        scanf("%d", &more);
        if (more == 1) 
        {
            newNode = (struct Node *)malloc(sizeof(struct Node));
            if (newNode == 0) 
            {
                printf("Memory not allocated.\n");
                exit(1);
            }
            printf("Enter data for new node: ");
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

// Function 2: Print linked list and node count
void printList(struct Node *head, int count) {
    struct Node *temp = head;

    printf("\nThe linked list is: ");
    while (temp != 0) 
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    printf("Total number of nodes: %d\n", count);
}

void main()  
{
    struct Node *head = 0;
    int count = 0;

    // Function 1: Create list
    head = createList(&count);

    // Function 2: Print list
    printList(head, count);
    
}

