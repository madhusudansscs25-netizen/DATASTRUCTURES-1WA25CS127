#include<stdio.h>
#include<stdlib.h>
struct node {
int data;
struct node *next;
};
struct node *createnode(int data) {

struct node *nn;
nn = (struct node *)malloc(sizeof(struct node));
nn->data = data;
nn->next = NULL;
return nn;

};
struct node *insertend(struct node*head, int data)
{
    struct node *nn, *temp;
    nn = createnode(data);
    if (head == NULL) {
        return nn;
    }
    temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = nn;
    return head;

};



struct node *create() {
struct node *head = NULL;
int n , i , data;
printf("enter number of nodes");
scanf("%d", &n);
for (i = 0;i <n;i++)
    {
        printf("enter the data");
        scanf("%d", &data);
        head = insertend(head, data);
    }
    return head;
};

void display(struct node *head)
{
    struct node *temp;
    if (head == NULL) {
        printf("list is empty");
        return;
    }
    temp = head;
    while (temp != NULL){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    }
    void sort(struct node *head) {
    struct node *i, *j;
    int temp;
    if (head == NULL){
    printf("list is empty");
    return;
    }
    for (i = head ; i->next != NULL;i= i->next) {
         for (j = i->next ;j != NULL;j= j->next) {
                if (i->data > j->data)
                {
                    temp = i->data;
                    i->data = j->data;
                    j->data = temp;

                }
    }}
    printf("list is sorted successfully");
    }
    struct node *reverse(struct node *head) {
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    printf("list reversed successfully");
    return prev;
};
struct node* concatenate(struct node *head1, struct node *head2)
{
    struct node *temp;
    if (head1 == NULL) {
        return head2;

    }
    if (head2 == NULL ) {
        return head1;
    }
    temp = head1;
    while (temp->next != NULL ) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
};
int main() {
struct node *head1 = NULL;
struct node *head2 = NULL;
int choice;
while(1){
    printf("\n------singly linked list------\n");
    printf("1- create list 1\n");
    printf("2- display list 1\n");
    printf("3- sort list 1\n");
    printf("4- reverse list 1\n");
    printf("5- create list 2\n");
    printf("6- display list 2\n");
    printf("7- concatenate list\n");
    printf("8- exit\n");
    printf("enter your choice");
    scanf("%d", &choice);
    switch(choice) {
    case 1:
        head1 = create();
        break;
    case 2:
        display(head1);
        break;
      case 3:
        sort(head1);
        break;
     case 4:
        head1 = reverse(head1);
        break;
    case 5:
        head2 = create();
        break;
    case 6:
       display(head2);
        break;
     case 7:
      head1 = concatenate(head1, head2);
      head2 = NULL;
      printf("list concatenated successfully\n");
      display(head1);

        break;

     case 8:
       printf("exiting the program");
       break;
       default:
       printf("invalid choice\n");

    }


}
return 0;
}

