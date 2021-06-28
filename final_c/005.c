//005
#include <stdio.h>
#define MAX(a, b)((a>b)?a:b)

int main(){
    int N, M;
    scanf("%d%d", &N, &M);
    int chosen[M], check[2*N+1];
    int id=0;

    for(int i=0; i<M; i++){
        scanf("%d", &chosen[i]);
    }
    for(int i=0; i<=2*N; i++){
        check[i]=0;
    }
    for(int i=0; i<M; i++){
        id=chosen[i];
        check[id]=1;
        check[id+N]=1;
    }

    int tmp=0, max=0;
    for(int i=1; i<=2*N; i++){
        if(check[i]==1){
            tmp++;
        }else{
            max=MAX(max, tmp);
            tmp=0;
        }
    }
    printf("%d", max);
}
