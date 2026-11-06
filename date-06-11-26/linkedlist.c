
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *current = NULL;


void create_SLL() {
    int choice;

    do {
        struct node *nn;
        nn = (struct node *)malloc(sizeof(struct node));

        if (nn == NULL) {
            printf("Memory allocation failed\n");
            return;
        }

        printf("Enter data: ");
        scanf("%d", &nn->data);

        nn->next = NULL;

        if (start == NULL) {
            start = nn;
            current = nn;
        } else {
            current->next = nn;
            current = nn;
        }

        printf("Do you want to continue? (1/0): ");
        scanf("%d", &choice);

    } while (choice == 1);
}


void display_SLL() {
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


void insertion_sll_beg() {
    struct node *nn;

    nn = (struct node *)malloc(sizeof(struct node));

    if (nn == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &nn->data);

    nn->next = start;
    start = nn;

    if (current == NULL) {
        current = nn;
    }

    printf("Node inserted at beginning\n");
}


void insertion_sll_end() {
    struct node *nn;

    nn = (struct node *)malloc(sizeof(struct node));

    if (nn == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &nn->data);

    nn->next = NULL;

    if (start == NULL) {
        start = nn;
        current = nn;
    } else {
        current->next = nn;
        current = nn;
    }

    printf("Node inserted at end\n");
}


void insertion_sll_pos() {
    struct node *nn, *temp;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        insertion_sll_beg();
        return;
    }

    temp = start;

    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    nn = (struct node *)malloc(sizeof(struct node));

    if (nn == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &nn->data);

    nn->next = temp->next;
    temp->next = nn;

    if (nn->next == NULL) {
        current = nn;
    }

    printf("Node inserted successfully\n");
}


void deletion_sll_beg() {
    struct node *temp;

    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = start;
    start = start->next;

    if (start == NULL) {
        current = NULL;
    }

    free(temp);

    printf("First node deleted\n");
}
void deletion_sll_end() {
    struct node *temp;

    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    if (start->next == NULL) {
        free(start);
        start = NULL;
        current = NULL;
    } else {
        temp = start;

        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;
        current = temp;
    }

    printf("Last node deleted\n");
}
void deletion_sll_pos() {
    struct node *temp, *prev;
    int pos, i;

    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }


    if (pos == 1) {
        deletion_sll_beg();
        return;
    }

    temp = start;
    prev = NULL;

    for (i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    prev->next = temp->next;


    if (temp == current) {
        current = prev;
    }

    free(temp);

    printf("Node deleted successfully\n");
}

int main() {
    int choice;

    do {
        printf("\n\n----- SINGLY LINKED LIST -----\n");
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
                create_SLL();
                break;

            case 2:
                display_SLL();
                break;

            case 3:
                insertion_sll_beg();
                break;

            case 4:
                insertion_sll_end();
                break;

            case 5:
                insertion_sll_pos();
                break;

            case 6:
                deletion_sll_beg();
                break;

            case 7:
                deletion_sll_end();
                break;

            case 8:
               deletion_sll_pos();
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






