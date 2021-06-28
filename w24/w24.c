//work24
#include <stdio.h>
#include <string.h>
#include <math.h>

//typedef enum scoreType{G, GPA, S} scoreType_t;
typedef enum score_s{one=95, two=87, three=82, four=78, five=75, six=70, seven=68, eight=65, nine=60, ten=50}score_t;
typedef struct student_s{
    char ID[5];
    double average_score;
} student_t;
typedef struct data_s{
    char G[3];
    char GPA[4];
    char S[8];
    score_t score;
}data_t;


int main(){
    data_t data[10]={
        {"A+", "4.3", "90-100", one},
        {"A", "4.0", "85-89", two},
        {"A-", "3.7", "80-84", three},
        {"B+", "3.3", "77-79", four},
        {"B", "3.0", "73-76", five},
        {"B-", "2.7", "70-72", six},
        {"C+", "2.3", "67-69", seven},
        {"C", "2.0", "63-66", eight},
        {"C-", "1.7", "60-62", nine},
        {"F", "0", "59以下", ten},
    };
    int M;
    scanf("%d", &M);
    char type[M][4];
    memset(type, '\0', sizeof(type));
    for(int i=0; i<M; i++){
        scanf("%s", type[i]);
    }

    for(int i=0; i<M; i++){
        //printf("%s\n", type[i]);
    }

    int N;
    double score_tmp=0;
    scanf("%d", &N);
    student_t student[N];
    for(int i=0; i<N; i++){
        student[i].average_score=0;
        scanf("%s", student[i].ID);
        if(strcmp(type[0], "GPA")==0){
            //printf("=======GPA\n");
            char new_score[4];
            memset(new_score, '\0', sizeof(new_score));
            //printf("....%s....%d", data[0].GPA, data[0].score);
            scanf("%s", new_score);
            for(int k=0; k<10; k++){
                if(strcmp(new_score, data[k].GPA)==0){
                    //printf("///%d\n", data[k].score);
                    score_tmp=data[k].score;break;
                }
            }
        }else if(strcmp(type[0], "G")==0){
            char new_score[3];memset(new_score, '\0', sizeof(new_score));
            //printf("GGGGGGGGGk");
            scanf("\n%s", new_score);
            for(int k=0; k<10; k++){
                if(strcmp(new_score, data[k].G)==0){
                    score_tmp=data[k].score;break;
                }
            }
        }else if(strcmp(type[0], "S")==0){
            char new_score[8];memset(new_score, '\0', sizeof(new_score));
            scanf("%s", new_score);
            for(int k=0; k<10; k++){
                if(strcmp(new_score, data[k].S)==0){
                    score_tmp=data[k].score;break;
                }
            }
        }
        student[i].average_score=score_tmp;
        for(int j=1; j<M; j++){
            if(strcmp(type[j], "GPA")==0){
                char new_score[4];
                memset(new_score, '\0', sizeof(new_score));
                scanf("%s", new_score);
                for(int k=0; k<10; k++){
                    if(strcmp(new_score, data[k].GPA)==0){
                        score_tmp=data[k].score;break;
                    }
                }
            }else if(strcmp(type[j], "G")==0){
                char new_score[3];memset(new_score, '\0', sizeof(new_score));
                scanf("\n%s", new_score);
                for(int k=0; k<10; k++){
                    if(strcmp(new_score, data[k].G)==0){
                        printf("%s\n", data[k].G);
                        score_tmp=data[k].score;break;
                    }
                }
            }else if(strcmp(type[j], "S")==0){
                char new_score[8];memset(new_score, '\0', sizeof(new_score));
                scanf("%s", new_score);
                for(int k=0; k<10; k++){
                    if(strcmp(new_score, data[k].S)==0){
                        score_tmp=data[k].score;break;
                    }
                }
            }
            student[i].average_score=(student[i].average_score*j+score_tmp)/(j+1);

        }//printf("%f\n", student[i].average_score);

    }

    int first=-1, second=-1, third=-1;
    for(int i=0; i<N; i++){
        if(student[i].average_score>student[first].average_score){
            third=second;
            second=first;
            first=i;
        }
        else if(student[i].average_score>student[second].average_score){
            third=second;
            second=i;
        }
        else if(student[i].average_score>student[third].average_score){
            third=i;
        }
    }

    printf("%s\n%.0f\n", student[first].ID, round(student[first].average_score));
    printf("%s\n%.0f\n", student[second].ID, round(student[second].average_score));
    printf("%s\n%.0f\n", student[third].ID, round(student[third].average_score));
}
