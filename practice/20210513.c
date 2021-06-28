//
#include <stdio.h>
struct on1{
unsigned light:1;
unsigned toaster:1;
int count;
unsigned ac:4;
unsigned flag: 1;
}kit1;
struct on2{
unsigned light:1;
unsigned :0;
unsigned toaster:1;
int count;
unsigned ac:4;
}kit2;
struct on3{
unsigned light:1;
int count;
}kit3;
struct on4{
unsigned light:1;
int count;
unsigned ac:3;
}kit4;
int main(){
    printf("%d\n", sizeof(kit1));//12
    printf("%d\n", sizeof(kit2));//16
    printf("%d\n", sizeof(kit3));//8
    printf("%d\n", sizeof(kit4));//12
}
