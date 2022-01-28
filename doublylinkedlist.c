#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node * next,*prev;
};
struct Node * head,*tail;
void create(int data);
void displayhead();

int main(){
   create(34);
   displayhead();
}
void create(int data){
    struct Node * ptr;
    ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=NULL;
    ptr->prev=NULL;
    head=ptr;
    tail=ptr;
}
void displayhead(){
    struct Node* ptr;
    ptr=head;
    if(head==NULL){
        printf("List is empty");
    }
    else{
    while(ptr != NULL){
       printf("%d\n",ptr->data);
       ptr=ptr->next;
}
    }
}