#include<stdio.h>
#include<stdlib.h>
struct Node{
  int data;
  struct Node * next;
};


struct Node * createlinkedlist(struct Node *);
void display(struct Node *);
struct Node * insertatbegin(struct Node *);
struct Node * insertatend(struct Node *);
struct Node * insertatindex(struct Node *,int index);

int main(){
    struct Node * head;
    head=createlinkedlist(head);
    display(head);
    head=insertatbegin(head);
    printf("After insert at begin\n");
    display(head);
    head=insertatend(head);
    printf("After insert at end\n");
    display(head);
}
struct Node * createlinkedlist(struct Node * head){
    int data;
    head=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter data you want to insert\n");
    scanf("%d",&data);
    head->data=data;
    head->next=NULL;
    return head;
}
void display(struct Node * head){
    struct Node* ptr;
    ptr=head;
    while(ptr != NULL){
       printf("%d\n",ptr->data);
       ptr=ptr->next;
    }
}
struct Node * insertatbegin(struct Node *head){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    int data;
    printf("Enter data you want to insert at begin\n");
    scanf("%d",&data);

    ptr->data = data;

    ptr->next = head;
    return ptr;
}
struct Node * insertatend(struct Node *head){
    struct Node * ptr,*p;
    p=head;
    ptr = (struct Node *) malloc(sizeof(struct Node));
    int data;
    printf("Enter data you want to insert at end\n");
    scanf("%d",&data);
    ptr->data = data;
    while(p->next != NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}
struct Node * insertatend(struct Node *head,int index){
    
}