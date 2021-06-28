//work20

#include <stdio.h>
#include <string.h>
#include <limits.h>

struct Word{
    char value[100];
    int count;
};


int check_same(struct Word *sortedWord,int wordCount,char*temp){
    int fg=0;
    for(int i=0;i<wordCount;i++){
        if(!strcmp( (sortedWord[i].value),temp) )
            fg=1;
            break;
    }
    return fg;
}


int main(){
    char A[1000], P[100], Q[100],A_copy[1000];
    fgets(A, 1000, stdin);
    if (strlen(A) > 0 && A[strlen(A) - 1] == '\n')
        A[strlen(A) - 1] = '\0';
    strcpy(A_copy,A);
    fgets(P, 100, stdin);
    fgets(Q, 100, stdin);
    if (strlen(P) > 0 && P[strlen(P) - 1] == '\n')
        P[strlen(P) - 1] = '\0';
    if (strlen(P) > 0 && P[strlen(P) - 1] == ' ')
        P[strlen(P) - 1] = '\0';
    if (strlen(Q) > 0 && Q[strlen(Q) - 1] == '\n')
        Q[strlen(Q) - 1] = '\0';
    if (strlen(Q) > 0 && Q[strlen(Q) - 1] == ' ')
        Q[strlen(Q) - 1] = '\0';

    int wordCount = 1;
    for (int i=0; i<strlen(A); i++)
        if(A[i] == ' ')
            wordCount++;

    char temp[wordCount][100];
    memset(temp,'\0',sizeof(temp));
    char *token = strtok(A, " ");
    int i = 0;
    while( token != NULL ) {
        strcpy(temp[i], token);
        token = strtok(NULL, " ");
        i++;
    }
    //change
    for(int i=0; i<wordCount; i++){
        if (!strcmp(temp[i],P))
            printf("%s", Q);
        else
            printf("%s", temp[i]);
        if(i!=wordCount-1)
         printf(" ");
    }
    printf("\n");
    // 1 complete
    //insert
    for(int i=0; i<wordCount; i++){
        if (!strcmp(temp[i],P))
            printf("%s %s", Q, P);
        else
            printf("%s", temp[i]);
        if(i!=wordCount-1)
         printf(" ");
    }
    printf("\n");
    // 2 complete
    //delete
    for(int i=0; i<wordCount; i++){
        if (strcmp(temp[i],P)){
            printf("%s", temp[i]);
            if(i!=wordCount-1)
          printf(" ");
        }
    }
    printf("\n");
    //3 complete

    struct Word sortedWord[wordCount];
    for(int i=0; i<wordCount; i++){
            strcpy(sortedWord[i] .value,temp[i]);
            sortedWord[i].count=1;
    }

    for(int i=0;i<wordCount;i++)
    {
        for(int j=i+1;j<wordCount;j++)
        {
            //printf("%d %d =%d\n",i,j,strcmp(sortedWord[i].value,sortedWord[j].value));
            if(strcmp(sortedWord[i].value,sortedWord[j].value)==0 && sortedWord[j].count!=0)
            {
                sortedWord[i].count+=sortedWord[j].count;
                struct Word Words={.value="",.count=0};
                sortedWord[j]=Words;
            }
        }
    }
    //sort  small is first and count is first
    for(int i=0;i<wordCount;i++)
    {
        for(int j=i;j<wordCount;j++)
        {
            //printf("%d %d =%d\n",i,j,strcmp(sortedWord[i].value,sortedWord[j].value));
            if(sortedWord[i].count<sortedWord[j].count)
            {   //swap
                struct Word swap = sortedWord[i];
                sortedWord[i]=sortedWord[j];
                sortedWord[j]=swap;
            }
            if(sortedWord[i].count==sortedWord[j].count){
                if( strcmp(sortedWord[i].value,sortedWord[j].value)>0){
                    struct Word swap = sortedWord[i];
                    sortedWord[i]=sortedWord[j];
                    sortedWord[j]=swap;
                }
            }
        }
    }

    for(int i=0;i<wordCount;i++){
        if(strcmp(sortedWord[i].value,"")!=0)
        printf("%s : %d\n", sortedWord[i].value, sortedWord[i].count);
    }
}
