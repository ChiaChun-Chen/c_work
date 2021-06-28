//work36
#include <stdio.h>
#include <string.h>
#define SIZE 20

typedef struct people_s{
    char name1[SIZE], name2[SIZE];
    int age;
    int birth_year, birth_month, birth_day;
    struct people_s *next;
}people_t;
typedef people_t* peoplep_t;

peoplep_t create(){
    char name1[SIZE], name2[SIZE], something_else;
    int age, birth_y, birth_m, birth_d;
    peoplep_t new_people;
    new_people=(peoplep_t)malloc(sizeof(people_t));
    memset(new_people->name1, '\0', SIZE);memset(new_people->name2, '\0', SIZE);
    memset(name1, '\0', SIZE); memset(name2, '\0', SIZE);
    scanf("%s%s", name1, name2);
    scanf("%d%d%d%d", &age, &birth_y, &birth_m, &birth_d);
    for(int i=1; i<sizeof(name1); i++){
        new_people->name1[i-1]=name1[i];
    }
    for(int i=0; i<sizeof(name2); i++){
        if(name2[i]=='"'){
            break;
        }else{
            new_people->name2[i]=name2[i];
        }
    }
    new_people->age=age;
    new_people->birth_year=birth_y;
    new_people->birth_month=birth_m;
    new_people->birth_day=birth_d;
    new_people->next=NULL;
    return new_people;
}

void push(peoplep_t *top){
    peoplep_t new_people=create();
    if((*top)==NULL){
        (*top)=new_people;
    }else{
        new_people->next=(*top);
        (*top)=new_people;
    }
}

void pop(peoplep_t *top){
    int job;
    scanf("%d", &job);
    if((*top)==NULL){
        printf("The Stack is empty\n");
        return;
    }
    switch(job){
    case 1:
        printf("%s %s\n", (*top)->name1, (*top)->name2);
        break;
    case 2:
        printf("%d\n", (*top)->age);
        break;
    case 3:
        printf("%d_%d_%d\n", (*top)->birth_year, (*top)->birth_month, (*top)->birth_day);
        break;
    }
    peoplep_t for_free=(*top);
    if((*top)->next!=NULL){
        (*top)=(*top)->next;
    }else{
        (*top)=NULL;
    }
    free(for_free);
}

int main(){
    peoplep_t top=NULL;
    int input;
    while(1){
        scanf("%d", &input);
        switch(input){
        case 1:
            push(&top);
            break;
        case 2:
            pop(&top);
            break;
        case 3:
            return 0;
        }
    }


}
