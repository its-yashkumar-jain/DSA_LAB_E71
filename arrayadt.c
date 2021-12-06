#include<stdio.h>
#include<stdlib.h>
struct Arrayadt{
  int capacity;
  int size;
  int * aptr;
};
void createarray(struct Arrayadt *);
void getarray(struct Arrayadt *);
void printarray(struct Arrayadt *);
void insertindex(struct Arrayadt *,int,int);
int insertend(struct Arrayadt *,int);
int sumelements(struct Arrayadt *);

int main(){
  struct Arrayadt arr;
  int com,index,ele,sumele;
  printf("Enter the capacity of the array \n");
  scanf("%d",&arr.capacity);
  printf("Enter the size of the array \n");
  scanf("%d",&arr.size);
  createarray(&arr);
  getarray(&arr);
  printarray(&arr);
  printf("\nEnter the commands to perform operation on array \n1. to insert an element at given index\n");
  printf("2. To insert at end of array :\n3. To sum all elements of array");
  scanf("%d",&com);
  switch (com)
  {
  case 1:
    printf("Enter element you want to insert :\n");
    scanf("%d",&ele);
    printf("Enter index at which you want to insert element :\n");
    scanf("%d",&index);
    insertindex(&arr,index,ele);
    printarray(&arr);
    break;
  case 2:
    printf("Enter element you want to insert :\n");
    scanf("%d",&ele);
    insertend(&arr,ele);
    printarray(&arr);
    break;
  case 3:
    
  default:
    break;
  }
}
void createarray (struct Arrayadt * arr){
   arr->aptr=(int *)calloc(arr->capacity,sizeof(int));
}
void getarray(struct Arrayadt * arr){
   for(int i=0;i<arr->size;i++){
     printf("Enter %d element of array : \n",i);
     scanf("%d",&(arr->aptr)[i]);
   }
}
void printarray(struct Arrayadt * arr){
   for(int i=0;i<arr->size;i++){
     printf("The %d element of array is : %d\n",i,(arr->aptr)[i]);
   }
}
void insertindex(struct Arrayadt * arr,int index,int ele){
  if(arr->size==arr->capacity){
    printf("Array is full cannot enter more elemnts\n");
  }
  else{
    for(int i=arr->size;i>=index;i--){
      (arr->aptr)[i+1]= (arr->aptr)[i];
    }
    (arr->aptr)[index]=ele;
    arr->size++;
  }
}
int insertend(struct Arrayadt * arr,int ele){
    (arr->aptr)[arr->size]=ele;
    arr->size++;
}