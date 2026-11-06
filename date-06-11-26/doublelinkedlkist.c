#include<Stdio.h>
#include<stdlib.h>


struct node{
int data;
struct node*prev;
struct node*next;
};
struct node *start = NULL;
struct node *current = NULL;

void create() {
struct node *nn;
nn = (struct node *)malloc(sizeof(struct node));
if (nn == NULL) {
    printf("craetion of node not possible");
    return;
    }

printf("enter the data");
scanf("%d", &nn->data);
nn->prev = NULL;
nn->next = NULL;
if (start == NULL) {
    start = nn;
    current = nn;
}
else {
    current->next = nn;
    nn->prev = current;
    current = nn;
    }
    printf("node created successfully;");
}
void insertion_dll_beg(){
struct node *nn;
nn = (struct node *)malloc(sizeof(struct node));
if (nn == 0)
{
     printf("craetion of node not possible");
     return;
}
printf("enter the data");
scanf("%d", &nn->data);
nn->next  = NULL;
nn->prev = NULL;
if (start = NULL)
{
 start = NULL;
 current = NULL;
}
else {
 start->prev = nn;;
 start = nn;
 }
 printf("node inserted successfully;");
}
void insertion_dll_end(){
struct node *nn;
nn = (struct node *)malloc(sizeof(struct node));
if (nn == NULL)
    {
     printf("creation of node not possible");
     return;
}
printf("enter te data");
scanf("%d", &nn->data);
nn->next = NULL;
nn->prev = NULL;
if (start = NULL)
{
    current = nn;
    start = nn;
}
else {
    current->next = nn;
    nn->prev = current;
    current = nn;

}

}
void deletion_sll_beg()
{ struct node *temp;

    if (start = NULL) {
        printf("list is empty deletion is not possible;");
        return;
    }
    temp = start;
    if (start->next=NULL)
    {
        start = NULL;
        current = NULL;

    } else{
    start = start->next;
    start->prev = NULL;
    }
free(temp);
printf("first node deleted successfully");

}

void deletionend() {
struct node *temp;
if (start = NULL)
    {
        printf("list is empty");
        return;
    }
temp = current;
if (start = current)
{
start = NULL;
current = NULL;
}
else {
    current = current->prev;
    current->next = NULL;
}
printf("last node successfully");
free(temp);
}
void insertion_at_pos() {
struct node *nn, *temp;
int pos , i;
nn = (struct node *)malloc(sizeof(struct node));
if (nn == 0)
    {
        printf("insertion is not possible");
        return;
    }
printf("enter the data");
scanf("%d", &nn->data);
printf("enter the pos");
scanf("%d", &pos);
if (pos <= 0)
{printf("invalid position");
free(nn);
return;

}
if (pos == 1)
{
    nn->prev = NULL;
    nn->next = NULL;
    if (start = NULL)
    {
        current = nn;

    }
    else {
        start->prev = nn;
        start = nn;
    }
    printf("node inserted succesfully");
    return;
}
temp = start ;
for (i = 1 ; i < pos-1 && temp != NULL; i++) {
    temp = temp->next;

}
if (temp == NULL) {
    printf("invalid not possible");
    free(nn);
    return;
}
nn->next = temp->next;
nn->prev = temp;
if (temp->next != NULL) {
    temp->next->prev = nn;
}
else {
    current = nn;
}
temp->next = nn;
printf("node insertedf successfully");
}
void deltion_postion() {
struct node *next, *temp;
int pos , i;
if (start == NULL) {
    printf("list is empty");
    return;
}
printf("enter the position");
scanf("%d", &pos);
if (pos <= 0) {
    printf("invalif position");
    return;

}
if (pos == 1){
   deletion_sll_beg();
   return;
}
temp = start;
for (i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;

}
if (temp = NULL) {
    printf("invalid position");
    return;

}
if (temp == current) {
   deletionend();
   return;

}
temp->prev->next = temp->next;
temp->next->prev = temp->prev;
free(temp);
printf("node deleted successfuly");

}
void display_dLL() {
    struct node *temp = start;

    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int choice;

    do {
        printf("\n\n----- doubly LINKED LIST -----\n");
        printf("1. Create SLL\n");
        printf("2. Display SLL\n");
        printf("3. Insertion at Beginning\n");
        printf("4. Insertion at End\n");
        printf("5. Insertion at Position\n");
        printf("6. Deletion at Beginning\n");
        printf("7. Deletion at End\n");
        printf("8. Deletion at position\n");
        printf("9.exit\n");


        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;

            case 2:
                display_dLL();
                break;

            case 3:
               insertion_dll_beg();
                break;

            case 4:
               insertion_dll_end();
                break;

            case 5:
                insertion_at_pos();
                break;

            case 6:
                deletion_sll_beg();
                break;

            case 7:
               deletionend();
                break;

            case 8:
               deltion_postion();
                break;
            case 9:
             printf("you are exiting the program\n");
             break;


            default:
                printf("Invalid choice\n");
        }

    } while (choice != 9);

    return 0;
}





