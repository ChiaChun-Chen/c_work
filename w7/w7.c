#include "stdio.h"
#include "stdlib.h"
double changeToPoint(char card, char *cardList, double *pointList){
    for(int i=0; i<13; i++){
        if(card==cardList[i]){
            return pointList[i];
        }
    }
}

int main(){
    char card[13]={'A','2','3','4','5','6','7','8','9','10','J','Q','K'};
    double point[13]={1,2,3,4,5,6,7,8,9,10,0.5,0.5,0.5};
    char A[3],B[3];
    scanf("%c\n%c\n%c\n%c\n%c\n%c",&A[0],&A[1],&A[2],&B[0],&B[1],&B[2]);
    double a=changeToPoint(A[0],card,point)+changeToPoint(A[1],card,point)+changeToPoint(A[2],card,point);
    double b=changeToPoint(B[0],card,point)+changeToPoint(B[1],card,point)+changeToPoint(B[2],card,point);
    if(a>10.5){
        a=0;
    }
    else if(b>10.5){
        b=0;
    }
    printf("%.1f\n%.1f\n",a,b);
    if(a>b) printf("A wins.");
    else if(b>a) printf("B wins.");
    else printf("It's a tie.");
}
