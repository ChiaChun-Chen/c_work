//002
#include <stdio.h>
#include <string.h>
#define make_work_arr(type) work_t work[101]
#define max(a,b)((a>b)?a:b)
typedef struct work_s{
    int machine, time;
}work_t;

typedef struct task_s{
    int p, ptr, pretime;
    make_work_arr(task_s);
}task_t;

int is_empty(task_t t){
    if(t.ptr>=t.p+1){
        return 1;
    }return 0;
}

int main(){
    int N=0, M=0;
    scanf("%d%d", &N, &M);
    int machine_pretime[N];
    int tmp=0, min=200, min_id=0, machine_pre_ptr=0, task_ptr=0;
    int ans[M], ans_ptr=0;
    for(int i=0; i<N; i++){
        machine_pretime[i]=0;
    }
    for(int i=0; i<M; i++){
        ans[i]=0;
    }

    task_t t[M+1];
    for(int i=1; i<=M; i++){
        scanf("%d", &t[i].p);
        t[i].pretime=0;
        t[i].ptr=1;
        for(int j=1; j<=t[i].p; j++){
            scanf("%d", &t[i].work[j].machine);
            scanf("%d", &t[i].work[j].time);
        }
    }

    int action=1, in_ans=0;
    while(action){
        action=0;
        for(int i=1; i<=M; i++){
            if(is_empty(t[i])){
                in_ans=0;
                for(int j=0; j<=M; j++){
                    if(i==ans[j]){
                        in_ans=1;
                        break;
                    }
                }
                if(in_ans==0){
                    ans[ans_ptr]=i;
                    ans_ptr++;
                }
                continue;
            }
            task_ptr=t[i].ptr;
            machine_pre_ptr=t[i].work[task_ptr].machine;
            tmp=max(machine_pretime[machine_pre_ptr]+t[i].work[task_ptr].time, t[i].pretime+t[i].work[task_ptr].time);
            if(tmp<min){
                min=tmp;
                min_id=i;
            }
            action=1;
        }
        if(action==1){
            task_ptr=t[min_id].ptr;
            machine_pre_ptr=t[min_id].work[task_ptr].machine;
            t[min_id].pretime=min;
            machine_pretime[machine_pre_ptr]=min;
            t[min_id].ptr++;
        }
        min=200;
        min_id=0;
    }

    int sum=0;
    for(int i=1; i<=M; i++){
        sum+=t[i].pretime;
    }

    for(int i=0; i<M; i++){
        printf("%d ", ans[i]);
    }
    printf("\n%d", sum);
}
