//w19

#include <stdio.h>
#define swap(x,y){int temp=x; x=y; y=7-temp;}

int main(){
    int A[4][3];
    int data[7]={0,0,0,0,0,0,0};

    int i;
    for(i=0; i<4; i++){
        A[i][0]=4;
        A[i][1]=1;
        A[i][2]=2;
    }

    int N,B[4];
    scanf("%d", &N);
    while(N>0){
        scanf("%d %d %d %d", &B[0], &B[1], &B[2], &B[3]);
        N--;
        for(i=0; i<4; i++){
            switch(B[i]){
            case 1:
                swap(A[i][0],A[i][1]);
                break;
            case 2:
                swap(A[i][1],A[i][0]);
                break;
            case 3:
                swap(A[i][2],A[i][1]);
                break;
            case 4:
                swap(A[i][1],A[i][2]);
                break;
            }
        }
    }

    int k;
    for(i=0; i<4; i++){
        k=A[i][1];
        data[k]++;
    }

    int max=0, max_item, sum=0;
    for(i=0; i<7; i++){
        if(data[i]>max){
            max=data[i];
            max_item=i;
        }
        sum=sum+data[i]*i;
    }

    switch(max){
    case 4:
        printf("18");
        break;
    case 3:
        printf("0");
        break;
    case 2:
        for(i=0; i<max_item; i++){
            if(data[i]==2){
                printf("%d", max_item*2);
                return 0;
            }
        }
        printf("%d", sum-max_item*2);
        break;
    case 1:
        printf("0");
        break;
    }
}
