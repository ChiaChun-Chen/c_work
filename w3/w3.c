//work3
//write in 20210228
#include <stdio.h>

int main(){
    int workhour_1,workhour_2,x,y;
    int totalhour;
    float tax, total_labor_insurance;
    scanf("%d%d%d%d",&workhour_1,&workhour_2,&x,&y);
    totalhour=workhour_1+workhour_2;
    tax=totalhour*x*0.08;
    total_labor_insurance=y*0.05;
    printf("%.1f\n%.1f\n%.1f",totalhour*x*0.92-total_labor_insurance,total_labor_insurance,tax);
}
