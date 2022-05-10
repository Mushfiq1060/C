#include<stdio.h>
struct Node
{
  int value;
  Node* next;
};
void pushFront(Node** head,int data) /// push value in the front
{
  Node* newNode=new Node();
  newNode->value=data;
  newNode->next=*head;
  *head=newNode;
}
void pushMiddle(Node** head,int position,int data) /// insert value after postion in linked list
{
  Node* newNode=new Node();
  newNode->value=data;
  Node* last=*head;
  for(int i=0;i<position-1;i++){
    last=last->next;
  }
  newNode->next=last->next;
  last->next=newNode;
}
void pushBack(Node** head,int data) /// push value in the last
{
  Node* newNode=new Node();
  newNode->value=data;
  newNode->next=NULL;
  Node* last=*head;
  if(*head==NULL){
    *head=newNode;
    return ;
  }
  while(last->next!=NULL){
    last=last->next;
  }
  last->next=newNode;
}
void popFront(Node** head) /// delete value from the front
{
  *head=(*head)->next;
}
void popMiddle(Node** head,int position) /// delete value of the position
{
  Node* last=*head;
  for(int i=0;i<position-2;i++){
    last=last->next;
  }
  last->next=last->next->next;
}
void popBack(Node** head) /// delete value from the last
{
  Node* last=*head;
  while(last->next->next!=NULL){
    last=last->next;
  }
  last->next=NULL;
}
void display(Node* head)
{
  Node* last=head;
  while(last!=NULL){
    printf("%d ",last->value);
    last=last->next;
  }
  printf("\n");
}
int main()
{
  Node* head=NULL;
  pushBack(&head,10);
  pushBack(&head,7);
  pushBack(&head,1);
  pushFront(&head,5);
  pushFront(&head,3);
  pushFront(&head,2);
  pushBack(&head,57);
  pushMiddle(&head,3,98);
  pushMiddle(&head,2,18);
  popFront(&head);
  popBack(&head);
  popMiddle(&head,3);
  display(head);
  return 0;
}