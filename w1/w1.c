//work1
//write in 20200228
#include <stdio.h>

int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%.1f\n%.1f",((-b)+sqrt(b*b-4*a*c))/(2*a),((-b)-sqrt(b*b-4*a*c))/(2*a));
}
