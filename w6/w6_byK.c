#include <stdio.h>
#include <stdlib.h>

double t183(int a,int b,int c,int d,int e){
    int monthly=183;
    double money;
    money=a*0.08+b*0.1393+c*0.1349+d*1.1287+e*1.4803;
    if(money-monthly>0) return monthly + abs(money-monthly);
    else return monthly;
}

double t383(int a,int b,int c,int d,int e){
    int monthly=383;
    double money;
    money=a*0.07+b*0.1304+c*0.1217+d*1.1127+e*1.2458;
    if(money-monthly>0) return monthly + abs(money-monthly);
    else return monthly;
}

double t983(int a,int b,int c,int d,int e){
    int monthly=983;
    double money;
    money=a*0.06+b*0.1087+c*0.1018+d*1.9572+e*1.1243;
    if(money-monthly>0) return monthly + abs(money-monthly);
    else return monthly;
}

int main()
{
    int a,b,c,d,e;
    double t1,t2,t3;

    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);

    t1=t183(a,b,c,d,e);
    t2=t383(a,b,c,d,e);
    t3=t983(a,b,c,d,e);

    if((t1 < t2)&&(t1 < t3)){
        printf("183");
    }
    else if((t2 < t1)&&(t2 < t3)){
        printf("383");
    }
    else{
        printf("983");
    }
    return 0;
}
