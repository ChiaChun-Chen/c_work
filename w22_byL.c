//work22

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define STR_N 300


int is_capital(char c){
    if(c >= 'A' && c <= 'Z')
        return 1;
    else
        return 0;
}

int main(){
    int k;
    scanf("%d", &k);
    while (getchar()!='\n');
    char s[STR_N] = "";
    fgets(s, STR_N, stdin);
    int max = 0;
    int cur = 0;
    int streak = 0;
    int capFlag = is_capital(s[0]);
    int length = strlen(s);

    for(int i=0; i<length; i++){
        if(is_capital(s[i])==capFlag){
            streak++;
        }
        else if(streak == k){
            capFlag = !capFlag;
            streak = 1;
        }
        else if(streak < k){
            capFlag = !capFlag;
            streak = 1;
            cur = 0;
        }
        if(streak == k){
            cur += k;
            if(cur>max)
                max=cur;
        }
        else if (streak > k){
            if(i+1 < length && is_capital(s[i+1]) != capFlag){
                cur = k;
                streak = k;
            }
        }
    }
    printf("%d\n", max);
    return 0;
}
