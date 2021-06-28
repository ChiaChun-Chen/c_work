//work29
#include <stdio.h>
#include <string.h>
#define GATEVALUE(TYPE) int(*gate_value)(int, int)
typedef struct gate_s{
    GATEVALUE(gate_s);
}gate_t;
int getvalue_empty(int input1, int input2){
    return input1;
}

typedef struct gate_and_s{
    GATEVALUE(gate_and_s);
}gate_and_t;
int getvalue_and(int input1, int input2){
    if(input1&&input2){
        return 1;
    }return 0;
}

typedef struct gate_or_s{
    GATEVALUE(gate_or_s);
}gate_or_t;
int getvalue_or(int input1, int input2){
    if(input1||input2){
        return 1;
    }return 0;
}

typedef struct gate_xor_s{
    GATEVALUE(gate_xor_s);
}gate_xor_t;
int getvalue_xor(int input1, int input2){
    if(input1==input2){
        return 0;
    }return 1;
}

typedef struct gate_not_s{
    GATEVALUE(gate_not_s);
}gate_not_t;
int getvalue_not(int input1, int input2){
    return 1-input1;
}

void char_to_int(int *input){
    char input_string[10];
    memset(input_string, '\0', sizeof(input_string));
    scanf("%s", input_string);
    char *ptr=input_string;
    ptr=strtok(ptr, ",");
    while(ptr!=NULL){
        *input=atoi(ptr);input++;
        ptr=strtok(NULL, ",");
    }
}

void str_to_arr(char *input_gate){
    char input_string[20];
    memset(input_string, '\0', sizeof(input_string));
    scanf("%s", input_string);
    char *ptr=input_string;
    ptr=strtok(ptr, ",");
    while(ptr!=NULL){
        *input_gate=*ptr;input_gate++;
        ptr=strtok(NULL, ",");
    }
}

int create_gate(char gate, int input1, int input2){
    if(gate=='A'){
        gate_and_t A;
        A.gate_value=getvalue_and;
        return A.gate_value(input1, input2);
    }else if(gate=='E'){
        gate_t E;
        E.gate_value=getvalue_empty;
        return E.gate_value(input1, input2);
    }else if(gate=='O'){
        gate_or_t O;
        O.gate_value=getvalue_or;
        return O.gate_value(input1, input2);
    }else if(gate=='X'){
        gate_xor_t X;
        X.gate_value=getvalue_xor;
        return X.gate_value(input1, input2);
    }else if(gate=='N'){
        gate_not_t N;
        N.gate_value=getvalue_not;
        return N.gate_value(input1, input2);
    }
}

int main(int argc, char *argv[]){
    int input[4], ans[3]; int tmp=0;
    char input_gate[6];
    ///
    ///輸入資料_I1~I4
    char_to_int(input);
    /*
    for(int i=0; i<4; i++){
        printf("%d\n", input[i]);
    }*/
    ///
    ///輸入資料A~F各閘種類
    str_to_arr(input_gate);
    /*
    for(int i=0; i<6; i++){
        printf("%c\n", input_gate[i]);
    }*/
    for(int i=0; i<3; i++){
        ans[i]=0;
    }
    ///
    ///01
    tmp=create_gate(input_gate[0], input[0], 0);
    ans[0]=create_gate(input_gate[1], tmp, input[1]);
    //printf("ans0=%d\n", ans[0]);
    ///
    ///02
    tmp=create_gate(input_gate[2], ans[0], input[2]);
    ans[1]=create_gate(input_gate[3], ans[0], tmp);
    //printf("ans1=%d\n", ans[1]);
    ///
    ///03
    tmp=create_gate(input_gate[4], input[3], 0);
    ans[2]=create_gate(input_gate[5], ans[1], tmp);
    //printf("ans2=%d\n", ans[2]);
    ///
    ///print answer
    printf("%d,%d,%d", ans[0], ans[1], ans[2]);
}
