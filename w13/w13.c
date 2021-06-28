//work13
#include "stdio.h"

int main(){
    int x1,x2,y1,y2;
    scanf("%d,%d",&x1,&y1);
    scanf("%d,%d",&x2,&y2);

    double m, b;
    m=(y1-y2)/(double)(x1-x2);
    b=(x2*y1-x1*y2)/(double)(x2-x1);

    if(m%1!=0){
        int mCarry=m/1;
        int mNumerator=m*10-mCarry*10;
    }
    if(b%1!=0){
        int bCarry=b/1;
        int bNumerator=b*10-bCarry*10;
    }


    if(m==1){
        if(b>0){
            printf("y=x+%.0f", b);
        }else if(b<0){
            printf("y=x%.0f", b);
        }
    }else if(m==-1){
        if(b>0){
            printf("y=-x+%.0f", b);
        }else if(b<0){
            printf("y=-x%.0f", b);
        }
    }else{
        if(b>0){
            printf("y=%.0fx+%.0f",m,b);
        }else if(b<0){
            printf("y=%.0fx%.0f",m,b);
        }
    }
}
