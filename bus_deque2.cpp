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
int isoverflow(struct Dequeue *);
int isunderflow(struct Dequeue *);
void enqueue(struct Dequeue *);
void display(struct Dequeue *);
void dequeue_rear(struct Dequeue *);
void dequeue_rear(struct Dequeue *);
void dequeue_front(struct Dequeue *);
void dequeue_front(struct Dequeue *);
int main(){
    struct Dequeue deq;
    int com;
    createdequeue(&deq);
    cout<<"Enter Commands to perform following operations"<<endl;
    cout<<"1. To enqueue i.e board passenger "<<endl;
    cout<<"2. To dequeue from rear "<<endl;
    cout<<"3. To dequeue from front "<<endl;
    cin>>com;
    while(1){
   if(com==1){
       enqueue(&deq);
       cout<<endl;
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
     deq->front=deq->capacity/2;
     deq->rear=deq->capacity/2;
     deq->dptr=(char *)calloc(deq->capacity,sizeof(char));
}
int isoverflow(struct Dequeue * deq){
    if(deq->front==0 && deq->rear==(deq->capacity)-1){
    return 1;
    }
    else return 0;
}
int isunderflow(struct Dequeue * deq){
    if((deq->front==(deq->capacity/2) && deq->rear==(deq->capacity/2))){
        return 1;
    }
    else return 0;
}
void enqueue(struct Dequeue * deq){
    int com;
    if(isoverflow(deq)){
        cout<<"Bus is full.No more passengers can board";
    }
    else
    {
    cout<<"Enter 1)To seat at front end\n2)To seat at rear end"<<endl;
    cin>>com;
    if(com==1){
        if(deq->front==0){
            cout<<"The front side is full.Please seat at rear end\n";
        }
        else{
                deq->front--;
                (deq->dptr)[deq->front]='F';
            }
        }
    else if(com==2){
        if(deq->rear==(deq->capacity)-1){
            cout<<"The rear side is full.Please seat at front end\n";
        }
        else{
                deq->rear++;
                (deq->dptr)[deq->rear]='R';
            }
        }
    }
}
void display(struct Dequeue * deq){
    int i=deq->front;
    cout<<"Elements of dequeue\n";
    while (i != deq->rear)
    {
        cout<<(deq->dptr)[i];
        i++;
    }
    cout<<(deq->dptr)[deq->rear];
}
void dequeue_rear(struct Dequeue * deq){
    if(isunderflow(deq)){
        cout<<"Bus is empty\n";
    }
    else{
     if(deq->rear==(deq->capacity/2)){
         cout<<"rear side is empty\n";
     }
     else{
         deq->rear--;
     }
    }
}
void dequeue_front(struct Dequeue * deq){
    if(isunderflow(deq)){
        cout<<"Bus is empty\n";
    }
    else{
     if(deq->front==(deq->capacity/2)){
         cout<<"front side is empty\n";
     }
     else{
         deq->front++;
     }
    }
}