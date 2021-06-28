//work32
#include <stdio.h>
#include <string.h>
#define min(a,b)((a<b)?a:b)

int search_left_id(int *aarray, int key, int key_id){
    int min_id=-1;
    for(int i=0; i<key_id; i++){
        if(aarray[i]<key){
            min_id=i;
        }
    }
    return min_id;
}

int search_right_id(int *aarray, int key, int key_id, int n){
    int max_id=n;
    for(int i=key_id+1; i<n; i++){
        if(aarray[i]<key){
            max_id=i;
            return max_id;
        }
    }
    return max_id;
}

int sum_radius(){
    int n;
    scanf("%d", &n);
    int aarray[n], r[n];
    int id_left, id_right;
    ///
    ///input the data
    for(int i=0; i<n; i++){
        scanf("%d", &aarray[i]);
        r[i]=0;
    }
    ///
    ///search for the minimun radius
    for(int i=0; i<n; i++){
        id_left=search_left_id(aarray, aarray[i], i);
        id_right=search_right_id(aarray, aarray[i], i, n);
        r[i]=min(i-id_left, id_right-i);//printf("left(%d),right(%d)\n", id_left, id_right);
    }
    ///
    ///add all radius
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=r[i];//printf("r[%d]=%d", i, r[i]);
    }
    printf("%d", sum);
}

int main(){
    sum_radius();
}
