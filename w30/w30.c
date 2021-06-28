//work30
#include <stdio.h>
#include <string.h>
#include <math.h>
#define make_work_arr(type) work_t work[101]
#define max(a,b) ((a>b)?a:b)
typedef struct work_s{
    int machine, time;
}work_t;

typedef struct task_s{
    int P;
    int ptr;
    int pre_time;
    make_work_arr(task_s);
}task_t;

int is_empty(task_t t){
    if(t.ptr>=t.P+1){
        return 1;
    }return 0;
}

int main(){
    int N=0, M=0;
    scanf("%d %d", &N, &M);
    int machine_pretime[N];
    int tmp=0, min=200, min_id=0, action=1, machine_pretime_ptr=0, task_ptr=0;
    for(int i=0; i<N; i++){     //initialize
        machine_pretime[i]=0;
    }
    ///
    ///輸入資料
    task_t t[M+1];
    for(int i=1; i<=M; i++){
        scanf("%d", &t[i].P);
        t[i].pre_time=0;t[i].ptr=1;
        for(int j=1; j<=t[i].P; j++){
            scanf("%d", &t[i].work[j].machine);
            scanf("%d", &t[i].work[j].time);
        }
        /*
        for(int j=0; j<=t[i].P; j++){
            printf("(%d,%d),%d\n", t[i].work[j].machine, t[i].work[j].time, t[i].ptr);
        }*/
    }
    ///
    ///排程
    while(action){
        action=0;
        for(int i=1; i<=M; i++){
            if(is_empty(t[i])){
                continue;
            }
            task_ptr=t[i].ptr;
            machine_pretime_ptr=t[i].work[task_ptr].machine;
            tmp=max(machine_pretime[machine_pretime_ptr], t[i].pre_time)+t[i].work[task_ptr].time;
            if(tmp<min){
                min=tmp;
                min_id=i;
            }
            action=1;
        }
        if(action==1){
            task_ptr=t[min_id].ptr;
            machine_pretime_ptr=t[min_id].work[task_ptr].machine;
            t[min_id].pre_time=min;
            machine_pretime[machine_pretime_ptr]=min;
            t[min_id].ptr+=1;
        }
        min=200;min_id=0;
    }
    ///
    ///print the total time for all tasks
    int sum=0;
    for(int i=1; i<=M; i++){
        sum+=t[i].pre_time;
        //printf("%d\n", t[i].pre_time);
    }
    printf("%d", sum);
    //printf("end\n");

}
