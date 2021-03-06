//work26
#include <stdio.h>

typedef struct task_s{
    int taskp[100];  ///who support this task
    int nop;    ///next place to place the support task
    int day;    ///days to complete this task
    int dayt;   ///total day until this task
}task_t;

void input(int n, task_t data[]){   ///load in data
    int c=0, id=0, index=0;
    int i, j;
    for(i=1; i<=n; i++){    ///init
        data[i].nop=0;
        data[i].dayt=-1;
    }
    for(i=1; i<=n; i++){
        scanf("%d", &data[i].day);  ///days to complete the task
        scanf("%d", &c);    ///support how many tasks
        for(j=0; j<c; j++){
            scanf("%d", &id);   ///the task i support
            index=data[id].nop; ///index is equal to nop, just create for simplify the next row
            data[id].taskp[index]=i;
            data[id].nop++;     ///update the new nop
        }
    }
}

void print(int n, task_t data[]){
    int i, j;
    for(i=1; i<=n; i++){
        printf("%d, %d, %d, %d\n", i, data[i].nop, data[i].day, data[i].dayt);
        for(j=0; j<data[i].nop; j++){
            printf("%d", data[i].taskp[j]);
        }printf("\n");
    }
}

int is_yet_compute(task_t t){
    if(t.dayt==-1){
        return 1;
    }else{return 0;}
}

int can_compute(task_t tasks[], task_t t){
    int flag=1, id=0;
    int i;
    for(i=0; i<t.nop; i++){
        id=t.taskp[i];
        if(tasks[id].dayt==-1){
            return 0;
        }
    }return 1;
}

int get_id(int n, task_t data[]){
    int i;
    for(i=1; i<=n; i++){
        if(is_yet_compute(data[i])&&can_compute(data, data[i])){
            return i;
        }
    }return -1;
}

int compute_day(task_t tasks[], task_t t){
    int max_day=0, id=0;
    int i;
    for(i=0; i<t.nop; i++){
        id=t.taskp[i];
        if(tasks[id].dayt>max_day){
            max_day=tasks[id].dayt;
        }
    }return (max_day+t.day);
}

void print_ans(int n, task_t data[]){
    int max_day=0;
    int i;
    for(i=1; i<=n; i++){
        if(data[i].dayt>max_day){
            max_day=data[i].dayt;
        }
    }
    printf("%d", max_day);
}

void f(){
    int n=0, count=0, id=0;
    scanf("%d", &n);
    task_t data[n+1];
    input(n, data);
    //print(n, data);

    while(count<100){
        id=get_id(n, data);
        if(id>=1){
            data[id].dayt=compute_day(data, data[id]);
            count++;
        }else{break;}
    }
    //print(n, data);
    print_ans(n, data);
    printf("\n");
}

int main(){
    int no=0;
    int i;
    scanf("%d", &no);
    for(i=0; i<no; i++){
        f();
    }
    return 0;
}
