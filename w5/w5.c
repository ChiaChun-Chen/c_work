#include "stdio.h"


int main(){
    int classA,classB,classC;
    int tA,tB,tC;
    int a[3],b[3],c[3];
    int a1=0,a2=0,a3=0,b1=0,b2=0,b3=0,c1=0,c2=0,c3=0;
    scanf("%d%d",&classA,&tA);
    switch(tA){
    case 1:
        scanf("%d",&a[0]);
        break;
    case 2:
        scanf("%d%d",&a[0],&a[1]);
        break;
    case 3:
        scanf("%d%d%d",&a[0],&a[1],&a[2]);
        break;
    }
    scanf("%d%d",&classB,&tB);
    switch(tB){
    case 1:
        scanf("%d",&b[0]);
        break;
    case 2:
        scanf("%d%d",&b[0],&b[1]);
        break;
    case 3:
        scanf("%d%d%d",&b[0],&b[1],&b[2]);
        break;
    }
    scanf("%d%d",&classC,&tC);
    switch(tC){
    case 1:
        scanf("%d",&c[0]);
        break;
    case 2:
        scanf("%d%d",&c[0],&c[1]);
        break;
    case 3:
        scanf("%d%d%d",&c[0],&c[1],&c[2]);
        break;
    }
    for(int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if(a[i]==b[j]){
                printf("%d and %d conflict on %d\n",classA,classB,b[j]);
            }
            if(a[i]==c[j]){
                printf("%d and %d conflict on %d\n",classA,classC,c[j]);
            }
            if(b[i]==c[j]){
                printf("%d and %d conflict on %d\n",classB,classC,b[i]);
            }
        }
    }
}
