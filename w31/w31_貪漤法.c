//work31
//貪漤法?
#include <stdio.h>
#include <string.h>

int min(int city_now, int *city_to_go, int N, int city[N+1][N+1]){
    int distance_min=1000, city_id=0, tmp=1000;
    for(int i=1; i<=N; i++){
        if(city_to_go[i]!=0){
            continue;
        }
        tmp=city[city_now][i];
        if(tmp<distance_min&&tmp!=0){
            distance_min=tmp;
            city_id=i;
        }
    }
    city_to_go[city_id]=1;
    return city_id;
}

int main(){
    int N=0, next_city=0, city_now=1, sum=0;
    scanf("%d", &N);
    int city[N+1][N+1], route[N], city_to_go[N+1];
    ///
    ///input the data
    for(int j=0; j<=N; j++){
        for(int i=0; i<=N; i++){
            scanf("%d", &city[j][i]);
        }
    }
    for(int i=0; i<=N; i++){
        city_to_go[i]=0;
    }
    for(int i=0; i<N; i++){
        route[i]=0;
    }
    route[0]=1;
    city_to_go[0]=1;city_to_go[1]=1;
    ///
    ///make the route
    for(int i=1; i<=N; i++){
        next_city=min(city_now, city_to_go, N, city);
        if(next_city==0){
            break;
        }else{
            route[i]=next_city;
            sum+=city[city_now][next_city];
            city_now=next_city;
            next_city=0;
        }
    }
    ///
    ///print out the route
    /*
    for(int i=0; i<N; i++){
        printf("%d->", route[i]);
    }*/
    ///
    ///print out the shortest time
    printf("%d", sum);
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
