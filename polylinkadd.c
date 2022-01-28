//Add two polynomials using linked list
#include<stdio.h>
#include<stdlib.h>
struct Polynomial
{
    int coeff;
    int expo;
    struct Polynomial* next;
};

struct Polynomial * createpolyequation(struct Polynomial* p,int);
struct Polynomial * addterms(struct Polynomial* p,int,int);
void polyadd(struct Polynomial*,struct Polynomial * , struct Polynomial *);
int main(){
    struct Polynomial* p1,*p2,*p3;
    int count1=0,count2=0,expo;
    int coeff,com;
    while(1){
        printf("Enter 1.For polynomial one\n2.For polynomial two\n");
        printf("Enter terms of polynomial p1 \n");
        scanf("%d",&com);
        if(com==1){
        if(count1==0){
          printf("Enter constant term\n");
          scanf("%d",&coeff);
             p1=createpolyequation(p1,coeff);
             count1++;
            }
       else if(count1>0){
        printf("Enter %d degree coefficient \n",count1);
        scanf("%d",&coeff);
        p1=addterms(p1,coeff,count1);
        count1++;
      }
    }
    else if(com==2){
        if(count2==0){
          printf("Enter constant term\n");
          scanf("%d",&coeff);
             p2=createpolyequation(p2,coeff);
             count2++;
        }
        else if(count1>0){
        printf("Enter %d degree coefficient \n",count2);
        scanf("%d",&coeff);
        p2=addterms(p1,coeff,count2);
        count2++;
    }
      printf("Enter -1 to exit or press any key to continue");
      scanf("%d",&com);
      if(com==-1)break;
   }
  //Performing addition
   polyadd(p1,p2,p3);
}
}
struct Polynomial * createpolyequation(struct Polynomial* p,int coeff){
    p=(struct Polynomial *)malloc(sizeof(struct Polynomial));
    p->coeff=coeff;
    p->expo=0;
    p->next=NULL;
    return p;
}
struct Polynomial * addterms(struct Polynomial* p,int coeff,int count1){
    struct Polynomial* pterm;
    pterm=(struct Polynomial *)malloc(sizeof(struct Polynomial));
    pterm->coeff=coeff;
    pterm->expo=count1;
    pterm->next=p;
    return pterm;
}

void polyadd(struct Polynomial* poly1, struct Polynomial* poly2,
             struct Polynomial* poly)
{
    while (poly1->next && poly2->next) {
        // If power of 1st polynomial is greater then 2nd,
        // then store 1st as it is and move its pointer
        if (poly1->expo > poly2->expo) {
            poly->expo = poly1->expo;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }

        // If power of 2nd polynomial is greater then 1st,
        // then store 2nd as it is and move its pointer
        else if (poly1->expo < poly2->expo) {
            poly->expo = poly2->expo;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }

        // If power of both polynomial numbers is same then
        // add their coefficients
        else {
            poly->expo= poly1->expo;
            poly->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        // Dynamically create new node
        poly->next
            = (struct Polynomial*)malloc(sizeof(struct Polynomial));
        poly = poly->next;
        poly->next = NULL;
    }
    while (poly1->next || poly2->next) {
        if (poly1->next) {
            poly->expo = poly1->expo;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if (poly2->next) {
            poly->expo = poly2->expo;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        poly->next
            = (struct Polynomial*)malloc(sizeof(struct Polynomial));
        poly = poly->next;
        poly->next = NULL;
    }
}