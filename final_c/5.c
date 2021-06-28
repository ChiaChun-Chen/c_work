//5
#include <stdio.h>

int main(){
    int N, M;
    scanf("%d%d", &N, &M);
    int chosen[M], chk[2*N+1];
    int id=0;
    for(int i=0; i<M; i++){
        scanf("%d", &chosen[i]);
    }

    for(int i=0; i<=2*N; i++){
        chk[i]=0;
    }
    for(int i=0; i<M; i++){
        id=chosen[i];
        chk[id]=1;
        chk[id+N]=1;
    }

    int tmp=0, max=0;
    for(int i=1; i<=2*N; i++){
        if(chk[i]==1){
            tmp+=1;
        }else{
            if(tmp>max){
                max=tmp;
            }
            tmp=0;
        }
    }
    printf("%d", max);
}
