#include<stdio.h>
#include<stdlib.h>
struct Mystack{
 int top;
 int size;
 int* sptr;
};
void createstack(struct Mystack *,int);
int main(){
   struct Mystack stack;
   int n;
   printf("Enter the value of size of stack :\n");
   scanf("%d",&n);
   createstack(&stack,n);
}
void createstack(struct Mystack* stack,int n){
    stack->sptr=(int *)calloc(n,sizeof(struct Mystack));
}