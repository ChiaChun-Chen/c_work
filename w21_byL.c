//work21

#include <stdio.h>
#include <string.h>
#define STR_N 300
int main(){
    char s1[STR_N];
    fgets(s1, STR_N, stdin);
    if (strlen(s1) > 0 && s1[strlen(s1)-1] == '\n' ) {
        s1[strlen(s1)-1] = '\0';
    }
    if (strlen(s1) > 0 && s1[strlen(s1)-1] == ' ' ) {
        s1[strlen(s1)-1] = '\0';
    }
    int n;
    scanf("%d ", &n);
    char words[n][STR_N];
    for(int i=0; i<n; i++){
        fgets(words[i], STR_N, stdin);
        if (strlen(words[i]) > 0 && words[i][strlen(words[i])-1] == '\n' ) {
            words[i][strlen(words[i])-1] = '\0';
        }
        if (strlen(words[i]) > 0 && words[i][strlen(words[i])-1] == ' ' ) {
            words[i][strlen(words[i])-1] = '\0';
        }
    }

    int count_word = 1;
    for(int i=0; i<strlen(s1); i++){
            if(s1[i] == ' ')
                count_word++;
    }
    char wordList[count_word][STR_N];

    strcpy(wordList[0], strtok(s1, " "));
    for (int i=1; i<count_word; i++) {
       strcpy(wordList[i], strtok(NULL, " "));
    }

    int A[n][count_word];
    memset(A,0,sizeof(A));
    for(int i=0;i<n;i++){
        int count_wordList = 1;
        for(int j=0; j<strlen(words[i]); j++){
                if(words[i][j] == ' ')
                    count_wordList++;
        }


        char List[count_wordList][STR_N];
        memset(List,'\0',sizeof(List));
        strcpy(List[0], strtok(words[i], " "));
        for (int j=1; j<count_wordList; j++) {
            strcpy(List[j], strtok(NULL, " "));
        }

        for (int j=0; j<count_wordList; j++) {
            for(int k=j+1;k<count_wordList;k++){
                if(strcmp(List[k],List[j])==0)
                    strcpy(List[j],"");
            }
        }


  for(int k=0;k<count_wordList;k++){
         for(int j=0;j<count_word;j++){
                if(strcmp(List[k],wordList[j])==0 && strcmp(List[k],"")!=0)
                    A[i][j]=1;
            }
        }
    }

    int ans=0;
    for(int i=0;i<n;i++){

        for(int k=i+1;k<n;k++){
            int array[count_word];
            memset(array,0,sizeof(array));
            for(int j=0;j<count_word;j++){
              if(A[i][j]==1 && A[k][j]==1)
               array[j]=0;
              else
                     array[j]=A[i][j]|A[k][j];
            }
            int num=0;

            for(int j=0;j<count_word;j++){
                    num+=array[j];
            }
            if(num==count_word)
                ans++;
        }
    }
    printf("%d",ans);


}
