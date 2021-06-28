#include <stdio.h>

void one_graph(int num){
 int i , j;
 for(i = 1;i <= num/2 + 1;i++){
  for(j= 1 ; j <= i; j++){
   printf("*");
  }
  printf("\n");
 }
 for(i = num/2; i > 0; i--){
  for(j =  i; j > 0;j--){
   printf("*");
  }
  printf("\n");
 }
}

void two_graph(int num){
 int i, j , k;
 for ( i=0; i<=num/2; i++){
  for ( j=num/2; j>i; j--)
   printf(".");
  for ( k=0; k<=i; k++)
   printf("*");
  printf("\n");
 }
 for(i = 1; i <= num/2; i++){
  for(j = 1;j <= ( i );j++){
   printf(".");
  }
  for(j = num/2 - i;j >=0;j--){
   printf("*");
  }
  printf("\n");

 }

}

void three_graph(int num){
 int i,j,k;
 for ( i=0; i<=num/2; i++){
  for ( j=num/2; j>i; j--)
   printf(".");
  for ( k=0; k<=2*i; k++)
   printf("*");
  printf("\n");
 }

 for(i = 1; i <= num/2; i++){


  for(j = 1;j <= ( i );j++){
   printf(".");
  }


  for(j = 1;j <= ( num - 2 * i );j++){
   printf("*");
  }
  printf("\n");

 }
}


int main(){

 int graph,row ;
 scanf("%d", &graph);
 scanf("%d", &row) ;
 if(graph == 1){
  one_graph(row);
 }
 if(graph == 2){
  two_graph(row);
 }
 if(graph == 3){
  three_graph(row);
 }

 return 0 ;
}
