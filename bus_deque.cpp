#include<iostream>
using namespace std;
struct Dequeue
{ 
   //max size is 30
   int capacity;
   int front;
   int rear;
   char * dptr;
};
void createdequeue(struct Dequeue *);
int getfront(struct Dequeue *);
int getrear(struct Dequeue *);
int isoverflow(struct Dequeue *);
int isunderflow(struct Dequeue *);
void enqueue_rear(struct Dequeue *);
void dequeue_rear(struct Dequeue *);
void dequeue_front(struct Dequeue *);
void display(struct Dequeue *);


int main(){
   struct Dequeue deq;
   int com;
   createdequeue(&deq);
   cout<<"Enter Commands to perform following operations"<<endl;
   cout<<"1. To enqueue from rear "<<endl;
   cout<<"2. To dequeue from rear "<<endl;
   cout<<"3. To dequeue from front "<<endl;
   cin>>com;
   while(1){
   if(com==1){
       enqueue_rear(&deq);
       display(&deq);
   }
   else if(com==2){
       dequeue_rear(&deq);
       display(&deq);
   }
   else if(com==3){
       dequeue_front(&deq);
       display(&deq);
   }
   cout<<endl;
   cin>>com;
   if(com==-1){
       break;
   }
   }

}
void createdequeue(struct Dequeue * deq){
     deq->capacity=30;
     deq->front=-1;
     deq->rear=-1;
     deq->dptr=(char *)calloc(deq->capacity,sizeof(char));
}
int getrear(struct Dequeue * deq){
     cout<<"The value of rear is : "<<deq->rear<<endl;
     cout<<"The value at rear is : "<<(deq->dptr)[deq->rear];
     return (deq->dptr)[deq->rear];
}
int getfront(struct Dequeue * deq){
     cout<<"The value of front is : "<<deq->front<<endl;
     cout<<"The value at front is : "<<(deq->dptr)[deq->front]<<endl;
     return (deq->dptr)[deq->front];
}
int isoverflow(struct Dequeue * deq){
    if((deq->front==0 && deq->rear==deq->capacity-1) || deq->front==deq->rear+1){
    return 1;
    }
    else return 0;
}
int isunderflow(struct Dequeue * deq){
    if((deq->front==-1) && (deq->rear==-1)){
        return 1;
    }
    else return 0;
}
void enqueue_rear(struct Dequeue * deq){
    if(isoverflow(deq)){
        cout<<"The queue is full cannot add further elements"<<endl;
    }
    else if(isunderflow(deq)){
        deq->front=deq->rear=0;
        (deq->dptr)[deq->rear]='A';
    }
    else if(deq->rear==deq->capacity-1){
        deq->rear=0;
        (deq->dptr)[deq->rear]='F';
    }
    else{
        deq->rear++;
        (deq->dptr)[deq->rear]='B';
    }
}
void dequeue_rear(struct Dequeue * deq){
    if(isunderflow(deq)){
        cout<<"The queue is empty cannot remove elements i.e. no passenger"<<endl;
    }
    else if(deq->front==deq->rear){
        deq->front==-1;
        deq->rear==-1;
    }
    else if(deq->rear==0){
        deq->rear=deq->capacity-1;
    }
    else{
        deq->rear--;
    }
}
void dequeue_front(struct Dequeue * deq){
    if(isunderflow(deq)){
        cout<<"The queue is empty cannot remove elements i.e. no passenger"<<endl;
    }
    else if(deq->front==deq->rear){
        deq->front==-1;
        deq->rear==-1;
    }
    else if(deq->front==deq->capacity-1){
        deq->front==0;
    }
    else{
        deq->front--;
    }
}
void display(struct Dequeue * deq){
    int i=deq->front;
    cout<<"Elements of dequeue\n";
    while (i != deq->rear)
    {
        cout<<(deq->dptr)[i];
        i=(i+1)%deq->capacity;
    }
    cout<<(deq->dptr)[deq->rear];
}