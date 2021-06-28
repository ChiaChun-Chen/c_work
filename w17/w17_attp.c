//work17
//according to teacher's PDF

#include <stdio.h>
#include <string.h>

int square(char data[100], int length, int n, int *i, int *last_j, int *last_i, int N_staticArrayWide, int *have_black){
    int time=0;
    while(*i<length){
        time++;
        if(data[*i]=='2'){
            (*i)++;
            //printf("%d, %d--------\n", *last_j, *last_i); ///
            square(data, length, n/2, i, last_j, last_i, N_staticArrayWide, have_black);
        }else if(data[*i]=='1'){

            *have_black=1;
            for(int j=0; j<n; j++){
                for(int i=0; i<n; i++){
                    printf("%d,%d\n", *last_j, *last_i);
                    //for_sort[*count]=*last_j*10+*last_i;
                    //(*count)+=1;
                    (*last_i)+=1;
                }
                (*last_j)+=1;   (*last_i)-=n;
            }
            if(time==2){
                (*last_i)-=n;
            }else if(time==1 || time==3){
                (*last_j)-=n;   (*last_i)+=n;
            }else{
                if((*last_i)+2>N_staticArrayWide-1){
                    (*last_i)=0;
                }else{
                    (*last_j)-=2*n; (*last_i)+=n;
                }
            }

            (*i)++;
            //printf("%d, %d--------\n", *last_j, *last_i);///
        }else if(data[*i]=='0'){
            (*i)++;
            //printf("%d, %d--------\n", *last_j, *last_i);///
            for(int j=0; j<n; j++){
                for(int i=0; i<n; i++){
                    (*last_i)+=1;
                }
                (*last_j)+=1;   (*last_i)-=n;
            }
            if(time==2){
                (*last_i)-=n;
            }else if(time==1 || time==3){
                (*last_j)-=n;   (*last_i)+=n;
            }else{
                if((*last_i)+2>N_staticArrayWide-1){
                    (*last_i)=0;
                }else{
                    (*last_j)-=2*n; (*last_i)+=n;
                }
            }
        }
        if(time==4){
            break;
        }
    }
    return *i;
}

int main(){
    int n=0, length=0, i=0;
    char data[100];
    scanf("%s", &data);
    scanf("%d", &n);

    int last_j=0, last_i=0;
    int have_black=0;

    length=strlen(data);
    square(data, length, n, &i, &last_j, &last_i, n, &have_black);
    if(have_black==0){
        printf("all white");
    }
}
