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
void delete(struct Arrayadt *,int);
int insertend(struct Arrayadt *,int);
int sumelements(struct Arrayadt *);
float avgelements(struct Arrayadt *);
int linearsearch(struct Arrayadt *,int);
int binarysearch(struct Arrayadt *,int);
void mergearray(struct Arrayadt *,struct Arrayadt *,struct Arrayadt *);
int getmax(struct Arrayadt *);
int getmin(struct Arrayadt *);
void intersection(struct Arrayadt *,struct Arrayadt *);
void reverseother(struct Arrayadt *);
void reversesame(struct Arrayadt *);
void insertsorted(struct Arrayadt *,int);
int issorted(struct Arrayadt *);

int main(){
  struct Arrayadt arr,arr2, arr3;
  int com,index,ele,sumele,key,searchindex,max,min;
  float avg;
  printf("Enter the capacity of the array \n");
  scanf("%d",&arr.capacity);
  printf("Enter the size of the array \n");
  scanf("%d",&arr.size);
  createarray(&arr);
  getarray(&arr);
  printarray(&arr);
  printf("\nEnter the commands to perform operation on array \n1. to insert an element at given index\n");
  printf("2. To insert at end of array :\n3. To sum all elements of array\n4. To find average of all elements in an array\n");
  printf("5. For linear search \n6. For Binary Search\n7. Delete an element from array\n");
  printf("8.To merge two arrays\n9. To get max element of array\n10. To get min elemnt of array\n");
  printf("11. To intersection of two arrays\n12. To reverse using another array\n13. To reverse using same array\n");
  printf("14. To insert in a sorted array\n15.To check if array is sorted or not\n");
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
    sumele=sumelements(&arr);
    printf("The sum of all elements of array is : %d\n",sumele);
    break;
  case 4:
     avg=avgelements(&arr);
     printf("The average of all elements of array is : %.2f\n",avg);
     break;
  case 5:
     printf("Enter element you want to search\n");
     scanf("%d",&key);
     searchindex=linearsearch(&arr,key);
     if(searchindex==-1){
       printf("Element not present in array");
     }
     else if(searchindex>=0){
       printf("Element %d present at %d index of array",key,searchindex);
     }
     break;
  case 6:
     printf("Enter element you want to search\n");
     scanf("%d",&key);
     searchindex=binarysearch(&arr,key);
     if(searchindex==-1){
       printf("Element not present in array");
     }
     else if(searchindex>=0){
       printf("Element %d present at %d index of array",key,searchindex);
     }
     break;
  case 7:
      printf("Enter index at which you want to delete element :\n");
      scanf("%d",&index);
      delete(&arr,index);
      printarray(&arr);
  case 8:
      printf("Enter the capacity of the array 2 \n");
      scanf("%d",&arr2.capacity);
      printf("Enter the size of the array 2 \n");
      scanf("%d",&arr2.size);
      createarray(&arr2);
      getarray(&arr2);
      printarray(&arr2);
      mergearray(&arr,&arr2,&arr3);
      printf("\n After merger :\n");
      printarray(&arr3);
      break;
  case 9: 
     max=getmax(&arr);
     printf("The max element of array is : %d\n",max);
     break;
  case 10:
     min=getmin(&arr);
     printf("The min element of array is : %d\n",min);
     break;
  case 11:
      printf("Enter the capacity of the array 2 \n");
      scanf("%d",&arr2.capacity);
      printf("Enter the size of the array 2 \n");
      scanf("%d",&arr2.size);
      createarray(&arr2);
      getarray(&arr2);
      printf("The elements of second array is :\n ");
      printarray(&arr2);
      intersection(&arr,&arr2);
      break;
  case 12:
      reverseother(&arr);
      printf("After reverse using another array\n");
      printarray(&arr);
      break;
  case 13:
     reversesame(&arr);
     printf("After reverse using same array\n");
     printarray(&arr);
     break;
  case 14:
     printf("enter element to insert in sorted array\n");
     scanf("%d",&key);
     insertsorted(&arr,key);
     printf("After Insertion in sorted array\n");
     printarray(&arr);
     break;
  case 15:
     key=issorted(&arr);
     if(key==0){
       printf("The array is not sorted\n");
     }
     else{
       printf("The array is sorted\n");
     }
    break;
  default:
     printf("Enter valid command");
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
int sumelements(struct Arrayadt * arr){

   int sumele=0;
   for(int i=0;i<arr->size;i++){
    sumele+= (arr->aptr)[i];
   }
   return sumele;
}
float avgelements(struct Arrayadt * arr){
   float sumele=0;
   for(int i=0;i<arr->size;i++){
    sumele+= (arr->aptr)[i];
   }
   return ((sumele)/(arr->size));
}
int linearsearch(struct Arrayadt * arr,int key){
  int flag;
    for(int i=0;i<arr->size;i++){
           if(arr->aptr[i]==key){
               return i;
           }
           else continue;
       }
  return -1;
}
int binarysearch(struct Arrayadt * arr,int key){

  int l=0;
  int r=arr->size;
  while (l <= r) {
     int m = l + (r - l) / 2;
     if (arr->aptr[m] == key)
       return m;
     if (arr->aptr[m] < key)
        l = m + 1;
     else
    r = m - 1;
  }
return -1;
}
void delete(struct Arrayadt * arr,int index){

    for(int i=index;i<(arr->size)-1;i++){
      (arr->aptr)[i]=(arr->aptr)[i+1];
    }
    arr->size--;
}
void mergearray(struct Arrayadt * a1,struct Arrayadt * a2,struct Arrayadt * a3){
    int i=0,j=0,k=0;
    a3->size = a1->size + a2 -> size;
    a3->capacity = a1->capacity + a2->capacity;
    a3->aptr=(int *)calloc((a3->capacity),sizeof(struct Arrayadt));
    for(i=0; i<a1->size; i++)
    {
        a3->aptr[i] = a1->aptr[i];
    }
    k = i;
    for(i=0; i<a2->size; i++)
    {
        a3->aptr[k] = a2->aptr[i];
        k++;
    }
}
int getmax(struct Arrayadt * a){

   int max;
    max=a->aptr[0];
    for(int i=1;i<a->capacity;i++){
        if (max<a->aptr[i])
        {
            max = a->aptr[i];
        }
        
    }
    return max;
}
int getmin(struct Arrayadt * a){

  int min, i;
    min = a->aptr[0];
    for(i=1;i<a->capacity;i++){
        if(min>a->aptr[i]){
            min = a->aptr[i];
        }
    }
    return min;
}
void intersection(struct Arrayadt * a1,struct Arrayadt * a2){
  int i,j,flag;
for(i = 0;i < a1->size;i++)
{
   for(j = 0;j < a2->size;j++)
   {
      if(a2->aptr[i] == a1->aptr[j])
      {
         flag = 1;
      }
    }
     if(flag == 1)
    {
    printf("%d ", a2->aptr[i]);
     }
  flag = 0;
  }
}
void reverseother(struct Arrayadt * a){
  int *b,i,j;
    b = (int*)calloc(a->size,sizeof(int));
    for(i=a->size-1,j=0;i>=0;i--,j++){
        b[j] = a->aptr[i];
    }
    for(i=0;i<a->size;i++){
        a->aptr[i] = b[i];
    }
    free(b);
}
void reversesame(struct Arrayadt * a){
  int i,j,temp;
    for(i=a->size-1,j=0;i>j;i--,j++){
        temp=a->aptr[i];
        a->aptr[i]=a->aptr[j];
        a->aptr[j]=temp;
    }
}
void insertsorted(struct Arrayadt * a,int key){
  int i=a->size-1;
    if(a->size!=a->capacity){
    while(i>=0 && a->aptr[i]>key){
        a->aptr[i+1] = a->aptr[i];
        i--;
    }
    a->aptr[i+1] = key;
    a->size++;
    }
}
int issorted(struct Arrayadt * a){
  int i;
    for(i=0;i<a->size-1;i++){
        if(a->aptr[i]>a->aptr[i+1]) return 0;
    }
    return 1;
}