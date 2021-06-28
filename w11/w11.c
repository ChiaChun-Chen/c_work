//work11
#include "stdio.h"

int change_from_2_to_10(int m_8) {
	int temp, sum=0, i, j;
	for(i=0; m_8>0; i++){
        temp=m_8%10;

        m_8=m_8/10;
        for(j=0; j<i; j++){
            if(temp==0){break;}
            temp=temp*2;
        }
        sum=sum+temp;
	}
	return sum;
}

void change_from_10_to_2(int m, int *num){
    int i, j;
    for(i=0; m>0; i++){
        num[i]=m%2;
        m=m/2;
    }
    for(j=10; j>=0; j--){
        printf("%d", num[j]);
    }
}

int countR(int m){
    int i=0;
    for(i=0; m>=0; i++){
        if(m==0||m==1) return i;
        else if(m%2==0){
            m=m/2;
        }
        else{
            m=(m+1)/2;
        }
    }
}

int main() {
	int m_8, m, flag, ans, i;
	do{
        int num[11]={0};
        int out=0;
        scanf("%d", &m_8);
        scanf("%d", &flag);
        m=change_from_2_to_10(m_8);
        for(i=0; m>=0; i++){
            ans=countR(m);
            out+=ans;
            m--;
        }
        change_from_10_to_2(out, &num);
        printf("\n");
	}while(flag==0);
}
