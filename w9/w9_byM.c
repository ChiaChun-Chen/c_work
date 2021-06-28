#include<stdio.h>
#include<math.h>

int g(int n,int k){
    if (n==1) return k;
    if (k<pow(2,n-1)){
        printf("0");
        return (g(n-1,k));
    }
    if (k>=pow(2,n-1)){
        printf("1");
        return g(n-1,pow(2,n)-1-k);
    }
}

int main(){
    int n,k,z=0;
    do{
        scanf("%d%d%d",&n,&k,&z);
        printf("%d\n",g(n,k));
    }while(z!=-1);
}
