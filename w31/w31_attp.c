//work31
#include <stdio.h>
#include <string.h>
#define min(a,b)((a<b)?a:b)

int record_distance(int N, int record[][1<<N], int city[][N+1], int v, int S){
    int t=0, ans=1000;
    if(record[v][S]>=0){
        return record[v][S];
    }
    for(int i=1; i<N; i++){
        if(!(S>>i&1)){
            t=record_distance(N, record, city, i+1, S|(1<<i));
            ans=min(ans, city[v][i+1]+t);
        }
    }
    return record[v][S]=ans;
}

int main(){
    int N=0, S=1, ans=0;
    scanf("%d", &N);
    int city[N+1][N+1], record[N+1][1<<N];
    ///
    ///input the data
    for(int j=0; j<=N; j++){
        for(int i=0; i<=N; i++){
            scanf("%d", &city[j][i]);
        }
    }
    for(int j=0; j<=N; j++){
        for(int i=0; i<(1<<N); i++){
            record[j][i]=-1;
        }
    }
    for(int i=0; i<=N; i++){
        record[i][(1<<N)-1]=0;
    }

    ///
    ///make the route
    ans=record_distance(N, record, city, 1, S);
    ///
    ///print out the route
    /*
    for(int j=0; j<=N; j++){
        for(int i=0; i<(1<<N); i++){
            printf("%d ", record[j][i]);
        }
        printf("\n");
    }*/

    ///
    ///print out the shortest time
    printf("%d\n", ans);
}

/*
9
0 1 2 3 4 5 6 7 8 9
1 0 4 2 3 6 3 3 5 1
2 4 0 3 1 4 5 2 2 2
3 2 3 0 2 5 3 4 2 1
4 3 1 2 0 3 3 7 3 1
5 6 4 5 3 0 2 8 4 7
6 3 5 3 3 2 0 9 7 3
7 3 2 4 7 8 9 0 1 5
8 5 2 2 3 4 7 1 0 2
9 1 2 1 1 7 3 5 2 0
*/
/*
5
0 1 2 3 4 5
1 0 2 3 4 5
2 2 0 6 7 8
3 3 6 0 9 10
4 4 7 9 0 11
5 5 8 10 11 0
*/
