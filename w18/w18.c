//w18
#include <stdio.h>
#define swap(x,y){int temp=x; x=y; y=7-temp;}

int main(){
    int A[9][3], B[9][3];
    int i;
    for(i=0; i<9; i++){
        A[i][0]=4;
        A[i][1]=1;
        A[i][2]=2;
    }

    int M, a, rc, count;
    scanf("%d", &M);

    while(M>0){
        scanf("%d", &a);
        rc=a/10; //row or column
        i=a%10;//printf("%d====\n", i);

        switch (rc){
        case 1:
            count=3;
            for(i; count>0; i=i+3){
                swap(A[i][1],A[i][0]);
                count--;
            }
            //front
            break;
        case 2:
            if(i==0){
                i=0;
                int B[9][3]={A[6][0],A[6][1],A[6][2],A[3][0],A[3][1],A[3][2],A[0][0],A[0][1],A[0][2],A[7][0],A[7][1],A[7][2],A[4][0],A[4][1],A[4][2],A[1][0],A[1][1],A[1][2],A[8][0],A[8][1],A[8][2],A[5][0],A[5][1],A[5][2],A[2][0],A[2][1],A[2][2]};
                for(i; i<9; i++){
                    A[i][1]=B[i][1];
                }
                count=3;i=0;
                for(i; count>0; i++){
                    swap(A[i][0],A[i][2]);
                    count--;
                }
            }else{
                count=3;i=i*3;
                for(i; count>0; i++){
                    swap(A[i][0],A[i][2]);
                    count--;
                }
            }

            break;
        }

        M--;
    }

    for(i=0; i<9; i++){
        printf("%d ", A[i][1]);
        if(i%3==2) printf("\n");
    }
}
