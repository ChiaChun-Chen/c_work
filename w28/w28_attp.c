//work28
#include <stdio.h>
#include <string.h>
#include <math.h>
#define shape_text(TYPE)\
    char name[10];\
    double (*perimeter)(struct TYPE*);
#define PI 3.14

typedef struct shape_s{
    shape_text(shape_s);
}shape_t;

typedef struct circle_s{
    shape_text(circle_s);
    float radius;   //為何要用 float, 不能用double
}circle_t;

typedef struct rectangle_s{
    shape_text(rectangle_s);
    float length, width;
}rectangle_t;

typedef struct square_s{
    shape_text(square_s);
    float edge;
}square_t;

typedef struct triangle_s{
    shape_text(triangle_s);
    float edge1, edge2, edge3;
}triangle_t;

double perimeter_c(circle_t *this){
    //printf("calculate the perimeter\n");
    double r=this->radius;

    //printf("%.2f\n", 2*PI*r);
    return 2*PI*r;
}

double perimeter_r(rectangle_t *this){
    double l=this->length, w=this->width;
    //free(this);
    //printf("%.2f\n", 2*l+2*w);
    return 2*l+2*w;
}

double perimeter_s(square_t *this){
    double edge=this->edge;
    //free(this);
    //printf("%.2f\n", 4*edge);
    return 4*edge;
}

double perimeter_t(triangle_t *this){
    double e1=this->edge1, e2=this->edge2, e3=this->edge3;
    //free(this);
    //printf("%.2f\n", e1+e2+e3);
    return e1+e2+e3;
}

double f(){
    int amount;
    char input[2];
    double sum;

    circle_t temp_c;
    rectangle_t temp_r;
    square_t temp_s;
    triangle_t temp_t;

    scanf("%s", input);
    //printf("%s\n", input);
    if(strcmp(input, "C")==0){
        //printf("to create a circle\n");
        circle_t *t=&temp_c;
        strcpy(t->name, "circle");
        scanf("%f", &(t->radius));
        //printf("%s, %f\n", t->name, t->radius);
        t->perimeter=perimeter_c;
        sum=t->perimeter(t);
        //printf("%f\n", sum);
    }else if(strcmp(input, "R")==0){
        //printf("to create a rectangle\n");
        rectangle_t *t=&temp_r;
        strcpy(t->name, "rectangle");
        scanf("%f%f", &(t->length), &t->width);
        //printf("%s, %f, %f\n", t->name, t->length, t->width);
        t->perimeter=perimeter_r;
        sum=t->perimeter(t);
        //printf("%f\n", sum);
    }else if(strcmp(input, "S")==0){
        //printf("to create a square\n");
        square_t *t=&temp_s;
        strcpy(t->name, "square");
        scanf("%f", &(t->edge));
        //printf("%s, %f\n", t->name, t->edge);
        t->perimeter=perimeter_s;
        sum=t->perimeter(t);
        //printf("%f\n", sum);
    }else if(strcmp(input, "T")==0){
        //printf("to create a triangle\n");
        triangle_t *t=&temp_t;
        strcpy(t->name, "triangle");
        scanf("%f%f%f", &(t->edge1), &t->edge2, &t->edge3);
        //printf("%s, %f, %f, %f\n", t->name, t->edge1, t->edge2, t->edge3);
        t->perimeter=perimeter_t;
        sum=t->perimeter(t);
        //printf("%f\n", sum);
    }
    return sum;
}

int main(){
    int amount, i=0;
    double ans=0;
    scanf("%d", &amount);
    double each[amount];
    for(i; i<amount; i++){
        each[i]=f();
        ans+=each[i];
    }
    for(i=0; i<amount; i++){
        printf("%.2f\n", (int)((each[i]*100)+0.5)/100.0);
    }
    //printf("%.2f\n", ans);
    printf("%.2f\n", (int)((ans*100)+0.5)/100.0);
}
