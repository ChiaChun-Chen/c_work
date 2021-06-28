//work16

#include <stdio.h>
#include <string.h>

int battle(int *count, int len, char *data, int m){
    int i=0, same=0, k;
    while(i<len-m){
        k=i;    (*count)++;
        for(i=k; i<k+m; i++){
            for(int j=i+1; j<k+m; j++){
                if(*(data+i)==*(data+j)){
                    same=1;
                    break;
                }
            }
        }
        if(same==1){
            (*count)--; same=0;
        }
        i=k+1;
    }
}

int main(){
    int m, count=0, len;
    char data[20];
    scanf("%s", data);
    len=strlen(data);
    scanf("%d", &m);

    battle(&count, len, data, m);
    printf("%d", count);
}
