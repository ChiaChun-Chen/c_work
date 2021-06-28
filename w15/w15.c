//work15

/*015 大數相加

輸入大數運算的模式，
以1代表大數相加；2代表大數相減；3代表大數相乘。
再輸入兩個20位數以上的整數做運算，
並輸出計算過後的結果。

sample input:
1
10000000000000000001
99999999999999999999

sample output:
110000000000000000000

--------------------------------

sample input:
2
10000100001000010000
100001000010000100001

sample output:
-90000900009000090001

--------------------------------

sample input:
3
10000100000000000001
12121212121212121212

sample output:
121213333333333333344242412121212121212
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 200

void String(int* big,char* str){
 int i=0,len=strlen(str);
 memset(big,0,4*MAX);
 for (i=len-1; i>=0;i--){
  big[len-i-1]=str[i]-'0';
 }
}

void Add(int *rst, int *a, int*b){
 int i,sum,carry;
 for (carry=i=0;i<MAX;i++){
  rst[i]=a[i]+b[i]+carry;
  carry=rst[i]/10;
  rst[i]%=10;
 }
}

void Mul(int *rst, int *a, int *b){
 int i,j,carry; int c=0;

 memset(rst,0,sizeof(int)*MAX);

 for(i=0; i<MAX; i++){
    if(a[i]==0) continue;
    for(j=0; i+j<MAX; j++){
        //aa=a[i]; bb=b[j];
        c=rst[i+j]+a[i]*b[j];
        //printf("%d, %d\n", rst[i+j], a[i]*b[j]);
        if(c>10){
            rst[i+j]=c-10;
            rst[i+j+1]+=1;
        }else{
            rst[i+j]=c;
        }
    }
 }
/*
 for (i=0;i<MAX;++i){
  if (a[i]==0) continue;
  for(j=0;i+j<MAX;j++){
   rst[i+j]+=a[i]*b[j];
  }
 }
 for (carry=i=0;i<MAX;i++){
  rst[i]+=carry;
  carry=rst[i]/10;
  rst[i]%=10;
 }*/
}

int Compare(int *a, int *b){
 int i=MAX-1;
 while(i>0 && a[i]==b[i]) i--;
 return a[i]-b[i];
}

void Sub(int *rst, int *a, int *b){
 int i,borrow;
 for(borrow=i=0; i<MAX; i++) {
     rst[i] = a[i]-b[i]-borrow;
     if(rst[i]<0) {
         borrow=1, rst[i]+=10;
     }else {
         borrow=0;
     }
    }
}

void Print(int *big){
 int i=MAX-1;
    for(i=MAX-1;i>0 && big[i]==0; i--);
    while(i>=0) printf("%d", big[i]), i--;
}


int main(){
 int i,j,k,len1,len2,state;
 char str1[MAX],str2[MAX];
 int num1[MAX],num2[MAX],num3[MAX];
 int *a,*b,*c;
 a=num1,b=num2,c=num3;
 scanf("%d",&state);
 scanf("%s",&str1);
 scanf("%s",&str2);
 len1=strlen(str1);
 len2=strlen(str2);
 String(a,str1);
 String(b,str2);
 memset(c,0,sizeof(int)*MAX);
 if (state==1){
  Add(c,b,a);
  Print(c);
 }
 if (state==2){
   printf("%d\n", strcmp(str1, str2));
  if (Compare(a,b)<0){
   printf("-");
   Sub(c,b,a);
   Print(c);
  }else if (Compare(a,b)>0){
   Sub(c,a,b);
   Print(c);
  }else
   printf("0");
 }
 if (state==3){
  Mul(c,b,a);
  Print(c);
 }
 return 0;
}
