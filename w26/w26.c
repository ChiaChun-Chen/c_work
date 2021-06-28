//work26
#include<stdio.h>
#include<string.h>

typedef struct data_s{
    int day;
    int K;
    int num[];
}data_t;

typedef struct group_s{
    int N;
    data_t project[];
}group_t;

void strtoIntarr(char *input, int *intArray){
    int i=0;
    char *p=strtok(input, " ");
    char *array[3];
    while(p!=NULL){
        array[i]=p;intArray[i]=atoi(array[i]);i++;
        p=strtok(NULL, " ");
    }
}

void initializer_int(int *intArray){
    int i=0;
    for(i=0; i<sizeof(intArray); i++){
        intArray[i]=0;
    }
}

int find_point(int array[][5], int n){
    int point=0;
    for(point; array[n][point]!=0; point++)
    return point;
}

void f(){
    int num_g, i, j, k;
    scanf("%d", &num_g);
    group_t group[num_g];
    char input[20];
    int input_int[20];
    int point;
    int total_day=0, cannot_count=0;

    for(i=1; i<=num_g; i++){
        scanf("%d", &group[i].N);
        data_t project[group[i].N];
        int need[group[i].N+1][5];
        for(j=0; j<=group[i].N; j++){
            initializer_int(need[j]);
        }
        for(j=1; j<=group[i].N; j++){
            memset(input, '\0', sizeof(input));
            scanf("%s", input);
            strtoIntarr(input, input_int);
            group[i].project[j].day=input_int[0];group[i].project[j].K=input_int[1];
            initializer_int(group[i].project[j].num);
            for(k=0; k<group[i].project[j].K; k++){
                group[i].project[j].num[k]=input_int[k+2];
                point=find_point(need, input_int[k+2]);
                need[input_int[k+2]][point]=j;
            }
        }
        for(j=1; j<=group[i].N; j++){
            cannot_count==0;
            for(k=0; k<5; k++){
                if(need[j][k]>j){
                    cannot_count=1;break;
                }
            }
            if(cannot_count==1){
                continue;
            }else{
                total_day+=group[i].project[j].day;
                for(k=0; k<group[i].project[j].K; k++){
                    cannot_count==0;
                    if(group[i].project[j].num[k]<j){
                       for(int kk=0; kk<5; kk++){
                            if(need[group[i].project[j].num[k]][kk]>j){
                                cannot_count=1;break;
                            }
                        }
                        if(cannot_count==1){
                            continue;
                        }else{
                            total_day+=group[i].project[group[i].project[j].num[k]].day;
                        }
                    }else{break;}
                }
            }
        }
    printf("%d\n", total_day);
    }
}

int main(){
    f();
}
