//practice
#include <stdio.h>
#include <string.h>
int main() {
    char one[]="123456789";
    char two[]="023456789";
    int ans=strcmp(one, two);
    if(ans>0){
        printf("one");
    }else{
        printf("two");
    }
}
