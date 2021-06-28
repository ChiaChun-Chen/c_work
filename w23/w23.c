//work23

#include <stdio.h>
#include <math.h>

double f1(int a, double x){
    return sqrt(a-x*x);
}

double f2(int a, double x){
    return (a*x*x*x+7*x)/sqrt(a+x);
}

double f1x(){
    int a, p, q, err;
    scanf("\n%d %d %d %d", &a, &p, &q, &err);
    double n=1;
    double dx=0, sum1=0, sum2=0, x=0;
    for(n; n>0; n=n*2){
        //printf("////////");
        dx=(q-p)/n;
        sum2=sum2+(q-p)*(f1(a,p))/n;
        for(x=(n*p+q-p)/n; x<q; x=(n*x+q-p)/n){
            //sum2=sum2+(f1(a,x)+f1(a,x+dx))*dx/2;
            sum2=sum2+2*(q-p)*(f1(a,x))/n;
        }
        sum2=sum2+(q-p)*(f1(a,q))/n;
        sum2/=2;
        //printf("n=%f, dx=%.10f, error=%.10f, sum1=%.12f, sum2=%.12f\n", n, dx, pow(10, -err), sum1, sum2);

        if(sum2-sum1<pow(10.0, -err)&&sum2-sum1>0){
            return sum2;
        }else{
            sum1=sum2;sum2=0;
        }

    }
}

double f2x(){
    int a, p, q, err;
    scanf("\n%d %d %d %d", &a, &p, &q, &err);
    double n=1;
    double dx=0, sum1=0, sum2=0, x=0;
    for(n=1; n>0; n=n*2){      ///若誤差過大則進入循環
        dx=(q-p)/n;
        for(x=p; x<q; x=(n*x+q-p)/n){       ///A(n)
            sum2=sum2+(q-p)*(f2(a,x)+f2(a,(n*x+q-p)/n))/(2*n);
        }
        if(sum2-sum1<pow(10.0, -err)&&(sum2-sum1)>0){     ///判斷誤差是否在誤差範圍內
            return sum2;
        }else{
            sum1=sum2;sum2=0;
        }

    }
}

int main(){
    int choose_func=0;
    scanf("%d", &choose_func);
    while(choose_func){
        if(choose_func==1){
            printf("%.12f\n", f1x());
        }else if(choose_func==2){
            printf("%.12f\n", f2x());
        }
        scanf("%d", &choose_func);
    }
}
