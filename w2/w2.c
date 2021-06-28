//work2
//write in 20200228
#include <stdio.h>
#include <math.h>
int change_to_number(char p){
    switch(p){
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case 'H':
        return 4;
    }
}

int main(){
    int stage=0,input,zero=0;
    char p1,p2,p3,p4,p5;
    scanf("%c\n%c\n%c\n%c\n%c",&p1,&p2,&p3,&p4,&p5);
    input=change_to_number(p1);
    if(input==0){
        zero+=1;
    }
    stage=(stage<<input)|(1<<(input-1));
    stage=stage&7;
    input=change_to_number(p2);
    if(input==0){
        zero+=1;
    }
    //printf("input2=%d\n",input);
    stage=(stage<<input)|(1<<(input-1));
    stage=stage&7;
    input=change_to_number(p3);
    if(input==0){
        zero+=1;
    }
    if(zero==3){
        stage=0;
        zero=0;
    }
    else{
        stage=(stage<<input)|(1<<(input-1));
        stage=stage&7;
    }
    //printf("input3=%d\n",input);

    input=change_to_number(p4);
    if(input==0){
        zero+=1;
    }
    if(zero==3){
        stage=0;
        zero=0;
    }
    else{
        stage=(stage<<input)|(1<<(input-1));
        stage=stage&7;
    }

    input=change_to_number(p5);
    if(input==0){
        zero+=1;
    }
    if(zero==3){
        stage=0;
        zero=0;
    }
    else{
        stage=(stage<<input)|(1<<(input-1));
        stage=stage&7;
    }

    printf("%d\n%d\n%d",stage&1,(stage>>1)&1,(stage>>2)&1);
}
