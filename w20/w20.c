//work20
#include <stdio.h>
#include <string.h>
void swap(char **str1, char **str2){
    char *temp=*str1;
    *str1=*str2;
    *str2=temp;
}

void change_file_to_two_dimention(char *file, char file_t[10][10]){
    int i=0, j=0;
    for(; *file!='\0'; file++){
        if(*file==' '){
            file_t[i][j]='\0';
            i++;j=0;
        }else{
            file_t[i][j]=*file;
            printf("\ni=%d, j=%d, file_t[i][j]=%c", i,j, file_t[i][j]);
            j++;
        }
    }

}

int main(){
    char *word_p[10], *word_q[10];
    char *file_a[100], *file_in_two_dimention[10][10];
    memset(file_in_two_dimention, 'h', sizeof(file_in_two_dimention)/8);
    printf("===%d\n", sizeof(char*));
    gets(file_a);
    scanf("%s %s", word_p, word_q);
    printf("stringA=%s, stringB=%s\n", word_p, word_q);
    swap(word_p, word_q);
    printf("stringA=%s, stringB=%s", word_p, word_q);
    change_file_to_two_dimention(file_a,file_in_two_dimention);
    printf("\n==============\n");
    puts(file_in_two_dimention[0]);
    puts(file_in_two_dimention[1]);
    printf("\n%c", file_in_two_dimention[1][1]);
}
