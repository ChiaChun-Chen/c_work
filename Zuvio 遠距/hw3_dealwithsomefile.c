//zuvio_work3 about file
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student_s{
    char id[5];
    int score_c, score_m, score_l;
}student_t;

void f(char fileName[]){
    int n;
    int i=0;
    student_t student[n+1];
    FILE *fp;
    fp=fopen(fileName, "w+");
    double sum=0, average=0;

    scanf("%d", &n);printf("n=%d\n", n);
    for(i=0; i<n; i=i+1){
        //memset(student[i].id, '\0', sizeof(student[i].id));
        scanf("%s", student[i].id);
        scanf("%d", &student[i].score_c);
        scanf("%d", &student[i].score_m);
        scanf("%d", &student[i].score_l); sum+=student[i].score_l;
        printf("%d=>%s, %d, %d, %d\n", i, student[i].id, student[i].score_c, student[i].score_m, student[i].score_l);
        fprintf(fp, "print...\n");
        fprintf(fp,"%s %d %d %d\n", student[i].id, student[i].score_c, student[i].score_m, student[i].score_l);
    }
    average=sum/n;
    for(i=0; i<n; i++){
        if(student[i].score_l>average){
            student[i].score_l++;
        }else if(student[i].score_l<average){
            student[i].score_l--;
        }
    }
    fprintf(fp, "\n");
    for(i=0; i<n; i++){
        printf("%s %f\n", student[i].id, (student[i].score_c+student[i].score_m+student[i].score_l)/3);
        fprintf(fp,"%s %d %d %d\n", student[i].id, student[i].score_c, student[i].score_m, student[i].score_l);
    }

    fclose(fp);

}

int main(){
    f("a.txt");
}
