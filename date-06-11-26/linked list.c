#include<stdio.h>
#include<stdlib.>
struct Node{
int data;
struct Node*next;
};
void createlist(struct Node **head,int n ){
struct Node *newNode,*temp;
int i,value;
for(i=1;i<=n;i++){
    printf("enter data for node %d",i);
    scanf("%d",&value);
    newNode=(struct Node*)malloc(sizeof(struct Node));}
    if(newNode==NULL){
        printf("memory allocation failed\n");
        return;
    }
    newNode->data=value;
    newNode->next=NULL;
    if(*head ==NULL){
        *head =newNode;
    }
    else{
        temp=*head;
        while(temp->next!=NULL){
            printf("%d",temp->data);
            temp=temp->next;
        }
        printf("NULL\n")
    }
void insert_first(){
struct Node *newNode;
newNode=(struct Node *)malloc(sizeof(struct Node));
printf("enter data");
scanf("%d",&newNode->data):
    newNode->=head;
    head=Newnode;'
    }
void insert_position(Node **head,int value,int position){
struct Node *newNode,*temp;
int pos i;
printf("enter a position "):
    scanf("%d",&pos);
    if(pos<1){
        printf("invalid position\n");
    }
    else if (pos==1){
        insert_position(head,value);

    }
    else{
        temp=*head;
        for(i=1;i<pos-1 && temp!=NULL;i++){
            temp=temp->next;
        }
        if (temp=NULL){
            printf("invalid position \n");
            return;
        }
        newNode=(node *)malloc(sizeof(node));
        if(newnode==null){
            printf("men")
            return;
        }
        newnode->data=value;
        newnode->next=temp->next;
        temp->next=newnode;

    }
    }

































