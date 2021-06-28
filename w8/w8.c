#include "stdio.h"
int main(){
    int graph, row;
    scanf("%d%d",&graph,&row);
    switch(graph){
    case 1:
        for(int i=1;i<=row/2+1;i++){
            for(int j=0; j<i; j++){
                printf("*");
            }
            printf("\n");
        }
        for(int i=row/2;i>0;i--){
            for(int j=0; j<i; j++){
                printf("*");
            }
            printf("\n");
        }
        break;
    case 2:
        for(int i=1; i<=row/2+1; i++){
            for(int j=0; j<row/2+1-i; j++){
                printf(".");
            }
            for(int j=0; j<i; j++){
                printf("*");
            }
            printf("\n");
        }
        for(int i=row/2; i>0; i--){
            for(int j=0; j<row/2+1-i; j++){
                printf(".");
            }
            for(int j=0; j<i; j++){
                printf("*");
            }
            printf("\n");
        }
        break;
    case 3:
        {int k=row/2;
        for(int i=1; i<=row; i=i+2){
            for(int j=0; j<k; j++){
                printf(".");
            }
            for(int j=0; j<i; j++){
                printf("*");
            }
            k--;
            printf("\n");
        }
        k=k+2;
        for(int i=row-2; i>0; i=i-2){
            for(int j=0; j<k; j++){
                printf(".");
            }
            for(int j=0; j<i; j++){
                printf("*");
            }
            k++;
            printf("\n");
        }
        break;}
    }
    return 0;
}
