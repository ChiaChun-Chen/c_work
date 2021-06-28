//work33
#include <stdio.h>
#include <string.h>
#define max(a, b)((a>b)?a:b)

typedef struct cave_s{
    int G;
    int next_cave[2];
}cave_t;

int find_gold(int N, int record[][1<<N-1], cave_t cave[N+1], int k, int S){
    int S1=S|(1<<(k-1));
    int Y=cave[k].next_cave[0];
    int Z=cave[k].next_cave[1];
    int t1=0, t2=0, ans=0;
    /*if(S1==S){
        printf(".....%d..\n", k);
        return 0;
    }*/
    if(cave[k].G==0&&Y==0&&Z==0){
        return record[k][S1]=0;
    }
    if(record[k][S1]>=0){
        return record[k][S1];
    }

    if(!((S1>>(Y-1))&1)){
        t1=find_gold(N, record, cave, Y, S1);
    }
    if(!((S1>>(Z-1))&1)){
        t2=find_gold(N, record, cave, Z, S1);
    }
    ans=max(t1+cave[k].G, t2+cave[k].G);
    return record[k][S1]=ans;
}

///
///透過前面找最多的金子時，隨時有紀錄當時的金子量在record[k][S]裡面
int find_gold_route(int N, int record[][1<<N-1], cave_t cave[N+1], int k, int S, int counter, int next_node[N], int gold){
    S=S|(1<<(k-1));     //以0,1組合成一個數。譬如S=101表示經過第1和3個cave
    cave_t X=cave[k];
    int Y=X.next_cave[0];
    int Z=X.next_cave[1];

    if(gold==0){        //遞迴時會不斷扣除gold直到gold==0，此時會將沿路的cave都印出來
        next_node[counter++]=k;
        for(int i=0; i<counter; i++){
            printf("%d ", next_node[i]);    //next_node裡面記錄這一條路線的cave   //因為next_node會根據中間的叉路而有所不同，所以是放到最後印出來
        }counter--;
        printf("\n");
        return 0;
    }

    if(record[Y][S|1<<(Y-1)]==gold-X.G){    //符合金子的數量才會進到迴圈中，所以金子的確定是放到判別式內

        gold-=X.G;
        next_node[counter++]=k;             //確定這條路正確才把X(也就是k)加入next_node
        find_gold_route(N, record, cave, Y, S, counter, next_node, gold);   //繼續遞迴往後找
        gold+=X.G;  counter--;
    }else{
        if(gold-X.G==0){
           for(int i=0; i<counter; i++){    //專門處理重複進入洞穴的狀況，因為那種情況record會不存在
                if(Y==next_node[i]){
                    next_node[counter++]=k;
                    next_node[counter]=Y;
                    for(int j=0; j<=counter; j++){
                        printf("%d ", next_node[j]);
                    }
                    printf("\n");counter--;
                }
            }
        }
    }
    if(record[Z][S|1<<(Z-1)]==gold-X.G){    //選擇Z路徑的情況
        gold-=X.G;
        next_node[counter++]=k;
        find_gold_route(N, record, cave, Z, S, counter, next_node, gold);
        gold+=X.G;  counter--;
    }else{
        if(gold-X.G==0){
            for(int i=0; i<counter; i++){
                if((Z==next_node[i])&&(gold-X.G==0)){
                    next_node[counter++]=k;
                    next_node[counter]=Z;
                    for(int j=0; j<=counter; j++){
                        printf("%d ", next_node[j]);
                    }
                    printf("\n");counter--;
                }
            }
        }
    }
}

int main(){
    int N, k, cave_name, S=0;
    scanf("%d", &N);
    scanf("%d", &k);
    cave_t cave[N+1];
    int record[N+1][(1<<N)-1];
    int next_node[N], counter=0;
    ///
    ///input data
    for(int i=1; i<=N; i++){
        scanf("%d%d%d%d", &cave_name, &cave[i].G, &cave[i].next_cave[0], &cave[i].next_cave[1]);
    }
    for(int j=0; j<=N; j++){
        for(int i=0; i<(1<<N); i++){
            record[j][i]=-1;
        }
    }
    ///
    ///find gold
    int ans=0;
    ans=find_gold(N, record, cave, k, S);

    find_gold_route(N, record, cave, k, 0, counter, next_node, ans);
    printf("%d", ans);
    return 0;
}

/*
5 1
1 6 2 4
2 5 3 4
3 7 2 5
4 4 2 5
5 0 0 0

3 1
1 6 2 3
2 5 1 3
3 0 0 0

4 2
1 5 2 3
2 4 3 4
3 0 0 0
4 0 0 0

5 3
1 2 2 5
2 0 0 0
3 1 1 2
4 3 3 5
5 0 0 0

4 1
1 12 2 3
2 999 3 4
3 0 4 1
4 4 1 2
*/
