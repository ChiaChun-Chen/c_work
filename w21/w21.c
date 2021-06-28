//work21
#include<stdio.h>
#include<string.h>
int main(){
    char basic[20][20], new_basic[20][20];
    int n;
    memset(basic, '\0', sizeof(basic));
    memset(new_basic, '\0', sizeof(new_basic));
    scanf("%s", basic);
    int new_i=0, new_j=0;
    for(int i=0; i<20; i++){     ///從一維轉成二維
        for(int j=0; j<20; j++){
            new_basic[new_i][new_j]=basic[i][j];
            if(basic[i][j]==' '){
                basic[i][j]='\0';
                new_basic[new_i][new_j]='\0';
                new_i++;new_j=0;
            }else{
                new_j++;
            }
            //printf("i=%d, j=%d, new_basic[i][j]=%c\n", i, j, new_basic[i][j]);
        }
    }
    for(int i=0; i<20; i++){    ///重新將二微陣列存回basic
        for(int j=0; j<20; j++){
            basic[i][j]=new_basic[i][j];
            //printf("basic[i][j]=%c\n", basic[i][j]);
        }
    }

    scanf("%d\n", &n);
    int amount_array[n][20];

    for(int k=0; k<n; k++){
        printf("n=%d\n", n);
        printf("k=%d\n", k);
        char temp[20][20];memset(temp, '\0', sizeof(temp));
        char new_temp[20][20];memset(new_temp, '\0', sizeof(new_temp));
        scanf("%s", temp);
        new_i=0;new_j=0;
        for(int i=0; i<20; i++){     ///從一維轉成二維
            for(int j=0; j<20; j++){
                new_temp[new_i][new_j]=temp[i][j];
                if(temp[i][j]==' '){
                    temp[i][j]='\0';
                    new_temp[new_i][new_j]='\0';
                    new_i++;new_j=0;
                }else{
                    new_j++;
                }
                //printf("i=%d, j=%d, temp[i][j]=%c\n", i, j, temp[i][j]);
            }
        }
        for(int i=0; i<20; i++){    ///重新將二維陣列放回temp
            for(int j=0; j<20; j++){
                temp[i][j]=new_temp[i][j];
                //printf("temp=%c\n", temp[i][j]);
            }
        }
        for(int i=0; i<20; i++){
            for(int j=0; j<20; j++){
                //printf("................");
                //printf("compare//%c, %c, %d\n", temp[i][j], basic[i][j], temp[i][j]==basic[i][j]);
                if(temp[i][j]==basic[i][j]){
                    amount_array[k][i]=1;
                }else{
                    amount_array[k][i]=0;
                    break;
                }
            }
        }
        //printf("===========================\n");
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<20; j++){
            //printf("////////////////////");
            printf("%d",amount_array[i][j]);
        }
        printf("\n");
    }

}
/*
happy birthday to you
4
happy to you
birthday birthday
to you
happy birthday
output:2
*/
