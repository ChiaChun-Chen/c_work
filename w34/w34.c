//work34
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node_s{
    int data;
    int power;
    struct node_s *next;
}node_t;

typedef node_t* nodep_t;

nodep_t create(int data){
    nodep_t new_node;
    new_node=(nodep_t)malloc(sizeof(node_t));
    new_node->data=data;
    new_node->power=0;
    new_node->next=NULL;
    return new_node;
}

void insert_from_front(nodep_t *p, int data){
    nodep_t new_node;
    new_node=create(data);
    if((*p)==NULL){
        (*p)=new_node;
    }else{
        new_node->next=(*p);
        (*p)=new_node;
    }
}

void store_power(nodep_t p){
    int power=0;
    nodep_t current=p;
    while(current!=NULL){
        current->power=power++;
        current=current->next;
    }
}

void print(nodep_t p){
    nodep_t front, current;
    front=current=p;
    while(current->next!=NULL){
        current=current->next;
    }
    printf("%d ", current->data);
    while(current!=p){
        front=p;
        while(front->next!=current){
            front=front->next;
        }
        current=front;
        printf("%d ", current->data);
    }
    printf("\n");
}

void print_from_front(nodep_t p){
    nodep_t current=p;
    while(current->next!=NULL){
        printf("%d ", current->data);
        current=current->next;
    }
    printf("%d\n", current->data);
}

void add(nodep_t p1, nodep_t p2){
    int tmp_add=0;
    nodep_t pp1=p1, pp2=p2, p_add=NULL;
    while((pp1->next!=NULL)&&(pp2->next!=NULL)){
        tmp_add=(pp1->data)+(pp2->data);
        insert_from_front(&p_add, tmp_add);
        pp1=pp1->next;
        pp2=pp2->next;
    }insert_from_front(&p_add, pp1->data+pp2->data);

    if(pp1->next!=NULL){
        pp1=pp1->next;
        insert_from_front(&p_add, pp1->data);
    }else if(pp2->next!=NULL){
        pp2=pp2->next;
        insert_from_front(&p_add, pp2->data);
    }
    print_from_front(p_add);
}

void minus(nodep_t p1, nodep_t p2){
    nodep_t pp1=p1, pp2=p2, p_minus=NULL;
    while((pp1->next!=NULL)&&(pp2->next!=NULL)){
        insert_from_front(&p_minus, pp1->data-pp2->data);
        pp1=pp1->next;
        pp2=pp2->next;
    }insert_from_front(&p_minus, pp1->data-pp2->data);

    if(pp1->next!=NULL){
        pp1=pp1->next;
        insert_from_front(&p_minus, pp1->data);
    }else if(pp2->next!=NULL){
        pp2=pp2->next;
        insert_from_front(&p_minus, 0-pp2->data);
    }
    print_from_front(p_minus);
}

void multiply(nodep_t p1, nodep_t p2){
    nodep_t pp1=p1, pp2=p2, p_mul=NULL, current=p_mul;
    int power_mul, tmp_mul;
    while(pp1->next!=NULL){                                 //²Ä¤@°é, pp2=p2, pp1=p1~null=>p_mul=p1~null
        insert_from_front(&p_mul, pp1->data*pp2->data);
        p_mul->power=pp1->power;
        pp1=pp1->next;
    }
    insert_from_front(&p_mul, pp1->data*pp2->data);
    p_mul->power=pp1->power;
    pp2=pp2->next;
    while(pp2->next!=NULL){
        pp1=p1;
        while(pp1->next!=NULL){
            power_mul=pp1->power+pp2->power;
            tmp_mul=pp1->data*pp2->data;
            current=p_mul;
            while(current->power!=power_mul){
                current=current->next;
            }
            current->data+=tmp_mul;
            pp1=pp1->next;
        }
        insert_from_front(&p_mul, pp1->data*pp2->data);
        p_mul->power=pp1->power+pp2->power;
        pp2=pp2->next;
    }
    pp1=p1;
    while(pp1->next!=NULL){
        power_mul=pp1->power+pp2->power;
        tmp_mul=pp1->data*pp2->data;
        current=p_mul;
        while(current->power!=power_mul){
            current=current->next;
        }
        current->data+=tmp_mul;
        pp1=pp1->next;
    }
    insert_from_front(&p_mul, pp1->data*pp2->data);
    print_from_front(p_mul);
}

int main(){
    char tmp='0';
    int tmp_int=0;
    nodep_t p1=NULL, p2=NULL;
    scanf("%d%c", &tmp_int, &tmp);
    while(tmp!='\n'){
        insert_from_front(&p1, tmp_int);
        scanf("%d%c", &tmp_int, &tmp);
    }insert_from_front(&p1, tmp_int);
    tmp='0';
    scanf("%d%c", &tmp_int, &tmp);
    while(tmp!='\n'){
        insert_from_front(&p2, tmp_int);
        scanf("%d%c", &tmp_int, &tmp);
    }insert_from_front(&p2, tmp_int);
    store_power(p1);
    store_power(p2);
    add(p1, p2);
    minus(p1, p2);
    multiply(p1, p2);

}

/*
2 3 0 1 -1
1 0 -1 4 -3 2
*/
