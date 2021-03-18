//work9
#include "stdio.h"

int main(){
    int n, k, flag;
    int G_1[2]={0}, G_2[4]={0}, G_3[8]={0}, G_4[16]={0}, G_5[32]={0}, G_6[64]={0};

    for(int i=1; i<2; i++){
        switch(i){
        case 1:{
            G_1[0]=0;
            G_1[1]=1;
        }
    case 2:{
        for(int j=0; j<2; j++){
            G_2[j]=G_1[j]|0;
            G_2[3-j]=G_1[j]|2;
    }
        }
    case 3:
        {for(int q=0; q<4; q++){
            G_3[q]=G_2[q]|0;
            G_3[7-q]=G_2[q]|4;}
        }
    case 4:
        {for(int k=0; k<8; k++){
            G_4[k]=G_3[k]|0;
            G_4[15-k]=G_3[k]|8;}
        }
    case 5:
        {for(int s=0; s<16; s++){
            G_5[s]=G_4[s]|0;
            G_5[31-s]=G_4[s]|16;}
        }
    case 6:
        {for(int t=0; t<32; t++){
            G_6[t]=G_5[t]|0;
            G_6[63-t]=G_5[t]|32;}
        }
        }
    }

    for(int i=0; i<4; i++){
        printf("cc2.......%d%d\n", (G_2[i]>>1)&1, G_2[i]&1);
    }
    for(int i=0; i<8; i++){
        printf("cc3.......%d%d%d\n", (G_3[i]>>2)&1, (G_3[i]>>1)&1, G_3[i]);
    }
    for(int i=0; i<16; i++){
        printf("%d%d%d%d\n",(G_4[i]>>3)&1, (G_4[i]>>2)&1, (G_4[i]>>1)&1, G_4[i]&1);
    }


    do{
        scanf("%d %d", &n, &k);
        scanf("%d", &flag);
        switch(n){
        case 1:
            printf("%d\n", G_1[k]&1);
            continue;
        case 2:
            printf("%d%d\n", (G_2[k]>>1)&1, G_2[k]&1);
            continue;
        case 3:
            printf("%d%d%d\n", (G_3[k]>>2)&1, (G_3[k]>>1)&1, G_3[k]);
            continue;
        case 4:
            printf("%d%d%d%d\n",(G_4[k]>>3)&1, (G_4[k]>>2)&1, (G_4[k]>>1)&1, G_4[k]&1);
            continue;
        case 5:
            printf("%d%d%d%d%d\n", (G_5[k]>>4)&1, (G_5[k]>>3)&1, (G_5[k]>>2)&1, (G_5[k]>>1)&1, G_5[k]&1);
            continue;
        case 6:
            printf("%d%d%d%d%d%d\n", (G_6[k]>>5)&1, (G_6[k]>>4)&1, (G_6[k]>>3)&1, (G_6[k]>>2)&1, (G_6[k]>>1)&1, G_6[k]);
            continue;
        }
        printf("test");
    }while(flag==0);
}
