//work25
#include <stdio.h>
#include <string.h>
#define SIZE 80

void chartoInt(char *charArray, int *intArray){
    int len=strlen(charArray);
    int i=len-1;
    for(i; i>=0; i--, intArray++){
        if(charArray[i]=='-'){
            i--;continue;
        }
        *intArray=charArray[i]-'0';
    }
}

void initializer_int(int *intArray){
    int i=0;
    for(i=0; i<SIZE; i++){
        intArray[i]=0;
    }
}

void add(int *num1, int *num2, int *sum_r){
    int tmp=0, carry=0, i=0;
    for(i; i<SIZE; i++){
        tmp=*num1+*num2+carry;
        if(tmp>9){
            sum_r[i]=tmp-10;carry=1;
        }else{sum_r[i]=tmp;carry=0;}
        tmp=0;num1++;num2++;
    }
}

void minus(int *num1, int *num2, int *ans_r){
    int borrow=0, tmp=0, i=0;
    for(i=0; i<SIZE; i++){
        tmp=*num1-*num2-borrow;
        if(tmp<0){
            ans_r[i]=tmp+10; borrow=1;
        }else{ans_r[i]=tmp;borrow=0;}
        tmp=0;num1++;num2++;
    }
}

void multiply(int *num1, int *num2, int *ans_r){
    int tmp=0, i, j, carry=0;
    initializer_int(ans_r);
    for(i=0; i<SIZE/2; i++){
        for(j=0; j<SIZE/2; j++){
            ans_r[i+j]+=num1[i]*num2[j]+carry;
            if(ans_r[i+j]>9){
                tmp=ans_r[i+j]%10;carry=ans_r[i+j]/10;
                ans_r[i+j]=tmp;
            }else{carry=0;}
            tmp=0;
        }
        ans_r[i+j+1]+=carry;carry=0;
    }
}

void myprint(int *intArray){
    int i=SIZE-1;
    for(i; i>0; i--){
        if(intArray[i]!=0){
            break;
        }
    }
    for(i; i>=0; i--){
        printf("%d", intArray[i]);
    }
    printf("\n");
}

int intArray_cmp(int *num1, int *num2){
    int i=SIZE-1;
    for(i; i>=0; i--){
        if(num1[i]>num2[i]){
            return 1;
        }else if(num2[i]>num1[i]){
            return 0;
        }
    }
    return 1;
}

void f(){
    char num_1[SIZE], num_2[SIZE];
    int choose;
    int num_int_1[SIZE], num_int_2[SIZE], sum_r[SIZE];
    int i=0, is_negative_num1=0, is_negative_num2=0;
    memset(num_1, '\0', sizeof(num_1));memset(num_2, '\0', sizeof(num_2));
    initializer_int(num_int_1);initializer_int(num_int_2);initializer_int(sum_r);

    /*
    gets(num_1);gets(num_2);
    chartoInt(num_1, num_int_1);chartoInt(num_2, num_int_2);
    for(i=0; i<strlen(num_1); i++){     ///測試矩陣轉換功能
        printf("%d", num_int_1[i]);
    }                                   ///
    add(num_int_1, num_int_2, sum_r);
    printf("----\n----");
    for(i=0; i<strlen(num_1)+1; i++){     ///測試加法
        printf("%d", sum_r[i]);
    }                                   ///
    printf("----\n----");
    minus(num_int_1, num_int_2, sum_r);
    for(i=0; i<strlen(num_1); i++){     ///測試減法
        printf("%d", sum_r[i]);
    }                                   ///
    printf("----\n----");
    multiply(num_int_1, num_int_2, sum_r);
    for(i=0; i<SIZE; i++){     ///測試乘法
        printf("%d", sum_r[i]);
    }                                   ///
    */
    ///
    ///start
    ///
    scanf("%d", &choose);
    scanf("%s", num_1);scanf("%s", num_2);
    if(num_1[0]=='-'){
        is_negative_num1=1;
    }
    if(num_2[0]=='-'){
        is_negative_num2=1;
    }
    chartoInt(num_1, num_int_1);chartoInt(num_2, num_int_2);
    switch(choose){
    case 1:
        if(is_negative_num1&&is_negative_num2){      ///--=>-(1+2)
            add(num_int_1, num_int_2, sum_r);//printf("////-(1+2)\n");
            printf("-");
        }else if(is_negative_num1){                 ///-+=>2-1
            if(intArray_cmp(num_int_1, num_int_2)){                ///-+(->+)=>-(1-2)
                minus(num_int_1, num_int_2, sum_r);//printf("////-(1-2)\n");
                printf("-");
            }else{minus(num_int_2, num_int_1, sum_r);}
        }else if(is_negative_num2){                 ///+-=>1-2
            if(intArray_cmp(num_int_1, num_int_2)==0){                ///+-(->+)=>-(2-1)
                minus(num_int_2, num_int_1, sum_r);//printf("////-(2-1)\n");
                printf("-");
            }else{minus(num_int_1, num_int_2, sum_r);}
        }else{add(num_int_1, num_int_2, sum_r);}    ///++=>1+2
        myprint(sum_r);break;
    case 2:
        if(is_negative_num1&&is_negative_num2){     ///--=>2-1
            if(intArray_cmp(num_int_1, num_int_2)){                ///--(1>2)=>-(1-2)
                minus(num_int_1, num_int_2, sum_r);
                printf("-");
            }else{minus(num_int_2, num_int_1, sum_r);}
        }else if(is_negative_num1){                 ///-+=>-(1+2)
            add(num_int_1, num_int_2, sum_r);
            printf("-");
        }else if(is_negative_num2){                 ///+-=>1+2
            add(num_int_1, num_int_2, sum_r);
        }else{                                      ///++=>1-2
            if(intArray_cmp(num_int_2, num_int_1)){                ///++(2>1)=>-(2-1)
                minus(num_int_2, num_int_1, sum_r);
                printf("-");
            }else{minus(num_int_1, num_int_2, sum_r);}
        }
        myprint(sum_r);break;
    case 3:
        if(is_negative_num1&&is_negative_num2){     ///--=>1*2
            multiply(num_int_1, num_int_2, sum_r);
        }else if(is_negative_num1||is_negative_num2){   ///+-/-+=>-1*2
            multiply(num_int_1, num_int_2, sum_r);
            printf("-");
        }else{multiply(num_int_1, num_int_2, sum_r);}   ///++=>1*2
        myprint(sum_r);break;
    }
}

int main(){
    f();
}
