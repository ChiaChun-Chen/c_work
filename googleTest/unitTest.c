#include <stdio.h> // main.c
#include <math.h>
#include <assert.h>
double computeBMI(int kg, int height) {
double BMI = 0.0, M = height/100.0;
if (kg<=0 || height<=0)
return -1;
BMI = round(100*kg/(M*M))/100; //�|�ˤ��J�����p��
return BMI;
}
int main() {
int kg = 52, kg2 = -1, height = 155, height2 = -1;
double expectedResult = 21.64f;
double result = computeBMI(kg, height);
assert(fabs(result-expectedResult)<0.0001);
assert(fabs(computeBMI(kg, height2)-(-1))<0.0001);
assert(fabs(computeBMI(kg2, height)-(-1))<0.0001);
assert(fabs(computeBMI(kg2, height2)-(-1))<0.0001);
printf("Hi\n");
return 0;
}
