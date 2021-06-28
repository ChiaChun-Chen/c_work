//work21_2
#include <stdio.h>
#include <string.h>

int main(){
    char input_file[100], file_2D[20][20];
    int i2=0, j2=0;
    gets(input_file);
    for(int i=0; i<20; i++){
        memset(file_2D[i], '\0', sizeof(file_2D[i]));
    }
    for(int i=0; input_file[i]!='\0'; i++){
        file_2D[j2][i2]=input_file[i];
        if(input_file[i]==' '){
            file_2D[j2][i2]='\0';
            j2++;i2=0;
        }else{
            i2++;
        }
    }
    for(int i=0; i<20; i++){    ///印出file_2D
        puts(file_2D[i]);
    }

    int n;
    scanf("%d\n", &n);

    int compare_array[n][20];
    for(int i=0; i<n; i++){
        for(int j=0; j<20; j++){
            compare_array[i][j]=0;
        }
    }


    char temp[100], temp_2D[20][20];
    for(int count=0; count<n; count++){
        printf("%d\n", count);
        gets(temp);
        i2=0;j2=0;
        for(int i=0; i<20; i++){        ///清空temp
            memset(temp_2D[i], '\0', sizeof(temp_2D[i]));
        }
        for(int i=0; temp[i]!='\0'; i++){   ///轉二維
            temp_2D[j2][i2]=temp[i];
            if(temp[i]==' '){
                temp_2D[j2][i2]='\0';
                j2++;i2=0;
            }else{
                i2++;
            }
        }

        int brk=0;
        for(int i=0; i<20; i++){
            for(int j=0; j<20; j++){
                for(int k=0; k<20; k++){
                    printf("%d, %d, %d, %c, %c\n", i, j, k, temp_2D[i][k], file_2D[j][k]);
                    if(temp_2D[i][k]==file_2D[j][k]){
                        compare_array[count][j]=1;continue;
                    }
                    if(temp_2D[i][0]=='\0'){
                        compare_array[count][j]=0;
                        brk=1;break;
                    }
                    if(temp_2D[i][k]!=file_2D[j][k]){
                        compare_array[count][j]=0;
                        break;
                    }

                }
                if(brk==1){
                    brk=0;break;
                }
            }
        }

        for(int i=0; i<20; i++){
            printf("%d", compare_array[count][i]);
        }
        printf("\n");
    }
}
