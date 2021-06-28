//001
#include <stdio.h>
#include <string.h>

typedef struct node_s{
    int data, power;
    struct node_s *next;
}node_t;
typedef node_t* nodep_t;

nodep_t create(int data){
    nodep_t new_n;
    new_n=(nodep_t)malloc(sizeof(node_t));
    new_n->data=data;
    new_n->power=0;
    new_n->next=NULL;
    return new_n;
}

void store_power(nodep_t p){
    nodep_t current=p;
    int power=0;
    while(current!=NULL){
        current->power=power;
        power++;
        current=current->next;
    }
}

void insert(nodep_t *p, int data){
    nodep_t new_n=create(data);
    if((*p)==NULL){
        (*p)=new_n;
    }else{
        new_n->next=(*p);
        (*p)=new_n;
    }
}

void print_ans(nodep_t p){
    nodep_t current=p;
    int sum=0;
    int no=1;
    while(current!=NULL){
        sum+=current->data;printf("%d\n", current->data);
        if(current->data!=0){
            no=0;
        }
        if((current->power)%2==1&&no==0){
            printf("%d ", current->data);
        }
        current=current->next;
    }
    printf("\n%d\n", sum);
}

void add(nodep_t p1, nodep_t p2){
    nodep_t pp1=p1, pp2=p2, p_add=NULL;
    while((pp1->next!=NULL)&&(pp2->next!=NULL)){
        insert(&p_add, (pp1->data)+(pp2->data));
        p_add->power=pp1->power;
        pp1=pp1->next;
        pp2=pp2->next;
    }insert(&p_add, pp1->data+pp2->data);

    if(pp1->next!=NULL){
        pp1=pp1->next;
        insert(&p_add, pp1->data);p_add->power=pp1->power;
    }else if(pp2->next!=NULL){
        pp2=pp2->next;
        insert(&p_add, pp2->data);p_add->power=pp2->power;
    }
    print_ans(p_add);

    nodep_t tmp=p_add;
    while(p_add!=NULL){
        //printf("%d\n", p_add->data);
        tmp=p_add;
        p_add=p_add->next;
        free(tmp);
    }
}

void minus(nodep_t p1, nodep_t p2){
    nodep_t pp1=p1, pp2=p2, p_minus=NULL;
    while((pp1->next!=NULL)&&(pp2->next!=NULL)){
        insert(&p_minus, (pp1->data)-(pp2->data));
        p_minus->power=pp1->power;
        pp1=pp1->next;
        pp2=pp2->next;
    }insert(&p_minus, pp1->data-pp2->data);

    if(pp1->next!=NULL){
        pp1=pp1->next;
        insert(&p_minus, pp1->data);p_minus->power=pp1->power;
    }else if(pp2->next!=NULL){
        pp2=pp2->next;
        insert(&p_minus, 0-pp2->data);p_minus->power=pp2->power;
    }
    print_ans(p_minus);

    nodep_t tmp=p_minus;
    while(p_minus!=NULL){
        tmp=p_minus;
        p_minus=p_minus->next;
        free(tmp);
    }
}

void multiply(nodep_t p1, nodep_t p2){
    nodep_t pp1=p1, pp2=p2, p_mul=NULL, current=p_mul;
    int power_mul, tmp_mul;
    while(pp1->next!=NULL){
        insert(&p_mul, pp1->data*pp2->data);
        p_mul->power=pp1->power+pp2->power;
        pp1=pp1->next;
    }insert(&p_mul, pp1->data*pp2->data);p_mul->power=pp1->power+pp2->power;
    pp2=pp2->next;
    while(pp2!=NULL){
        pp1=p1;
        while(pp1->next!=NULL){
            power_mul=pp1->power+pp2->power;tmp_mul=pp1->data*pp2->data;
            current=p_mul;
            while(current->power!=power_mul){
                current=current->next;
            }current->data+=tmp_mul;
            pp1=pp1->next;
        }insert(&p_mul, pp1->data*pp2->data);p_mul->power=pp1->power+pp2->power;
        pp2=pp2->next;
    }
    print_ans(p_mul);
}

int main(){
    char tmp='0';
    int tmp_int=0;
    nodep_t p1=NULL, p2=NULL;
    int start_p1=0, start_p2=0;

    char input1[1000], input2[1000];
    memset(input1, '\0', 1000);memset(input2, '\0', 1000);

    gets(input1);
    gets(input2);

    for(int i=0; i<sizeof(input1); i++){
        if(input1[i]=='\0'||input1[i]=='\n'){continue;}
        if(input1[i]=='-'){
            i++;
            tmp_int=input1[i]-'0';
            if(input1[i+1]!=' '&&input1[i]!=' '&&input1[i+1]!='\0'&&input1[i+1]!='\n'){
                i++;
                tmp_int=(input1[i]-'0')+tmp_int*10;
                if(input1[i+1]!=' '&&input1[i]!=' '&&input1[i+1]!='\0'&&input1[i+1]!='\n'){
                    i++;
                    tmp_int=(input1[i]-'0')+tmp_int*10;
                }
            }
            tmp_int=-tmp_int;
        }else{
            tmp_int=input1[i]-'0';
            if(input1[i+1]!=' '&&input1[i]!=' '&&input1[i+1]!='\0'&&input1[i+1]!='\n'){
                i++;
                tmp_int=(input1[i]-'0')+tmp_int*10;
                if(input1[i+1]!=' '&&input1[i]!=' '&&input1[i+1]!='\0'&&input1[i+1]!='\n'){
                    i++;
                    tmp_int=(input1[i]-'0')+tmp_int*10;
                }
            }
        }
        if(tmp_int==-16||tmp_int==-48){continue;}printf("%d\n", tmp_int);
        insert(&p1, tmp_int);
    }
    for(int i=0; i<sizeof(input2); i++){
        if(input2[i]=='\0'){continue;}
        if(input2[i]=='-'){
            i++;
            tmp_int=input2[i]-'0';
            if(input2[i+1]!=' '&&input2[i]!=' '&&input2[i+1]!='\0'){
                i++;
                tmp_int=(input2[i]-'0')+tmp_int*10;
                if(input2[i+1]!=' '&&input2[i]!=' '&&input2[i+1]!='\0'){
                    i++;
                    tmp_int=(input2[i]-'0')+tmp_int*10;
                }
            }
            tmp_int=-tmp_int;
        }else{
            tmp_int=input2[i]-'0';
            if(input2[i+1]!=' '&&input2[i]!=' '&&input2[i+1]!='\0'){
                i++;
                tmp_int=(input2[i]-'0')+tmp_int*10;
                if(input2[i+1]!=' '&&input2[i]!=' '&&input2[i+1]!='\0'){
                    i++;
                    tmp_int=(input2[i]-'0')+tmp_int*10;
                }
            }
        }
        if(tmp_int==-16||tmp_int==-48){continue;}printf("///%d\n", tmp_int);
        insert(&p2, tmp_int);
    }
    /*
    scanf("%d", &tmp_int);
    while(1){
        if(getc(tmp)){break;};
        insert(&p1, tmp_int);
        scanf("%d", &tmp_int, &tmp);
    }insert(&p1, tmp_int);printf(".......");
    scanf("%d%c", &tmp_int, &tmp);
    while(tmp==' '){
        insert(&p2, tmp_int);
        scanf("%d%c", &tmp_int, &tmp);
    }insert(&p2, tmp_int);*/

    store_power(p1);
    store_power(p2);

    add(p1, p2);
    minus(p1, p2);
    multiply(p1, p2);
}
/*
0 0 0 0 1
1 0 0 0 0*/
