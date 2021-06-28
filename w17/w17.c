//work17

#include "stdio.h"
int make_paragraph(char *string, int i, int last_j, int last_i, int layer, int picture_array[][n], int n, int count){
    if(count==0){
        return 1;
    }
    if(string[i]=='2'){
        //layer+=1
        //count=4
        return make_paragraph(string, i+1, last_j, last_i, layer+1, picture_array, n, 4);
    }else if(string[i]=='1'){
        picture_array[last_j][last_i]=1;
        //count--
        if(last_i==(n-1)){
            printf("%d, %d", last_j++, last_i);
            int weight=n>>layer;
            last_i=last_i-2*weight+1;
        }else{
            printf("%d, %d", last_j, last_i++);
        }
        return make_paragraph(string, i+1, last_j, last_i, layer, picture_array, n, count-1);
    }else if(string[i]=='0'){
        picture_array[last_j][last_i]=0;
        //count--
        if(last_i==(n-1)){
            last_j++;
            int weight=n>>layer;
            last_i=last_i-2*weight+1;
        }else{
            last_i++;
        }
        return make_paragraph(string, i+1, last_j, last_i, layer, picture_array, n, count-1);
    }
}

int main(){

    char string[100];
    scanf("%s", string);
    int length=0, i=0;
    while(string[i++]!='\0'){
        length+=1;
        //printf("%d", length); //test if the length is true
    }

    int n, last_j=0, last_i=0, layer=0;
    scanf("%d", &n);
    int picture_array[n][n];

    make_paragraph(string, 0, last_j, last_i, layer, picture_array, n, 0);
    for(int i=0; i<n; i++){
        printf("%d ", picture_array[0][i]);
    }
}
