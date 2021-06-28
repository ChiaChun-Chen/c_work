#include <stdio.h>

int main(){
 char x;
 float sumX;
 int i ;
 for(i = 0;i < 3; i++){
  scanf("%s", &x);
  if(x == 'A'){
   sumX += 1.0;
  }else if((x == 'J') || (x == 'Q') || (x == 'K')){
   sumX += 0.5 ;
  }else if(x == '2'){
   sumX += 2.0;
  }else if(x == '3'){
   sumX += 3.0;
  }else if(x == '4'){
   sumX += 4.0;
  }else if(x == '5'){
   sumX += 5.0;
  }else if(x == '6'){
   sumX += 6.0;
  }else if(x == '7'){
   sumX += 7.0;
  }else if(x == '8'){
   sumX += 8.0;
  }else if(x == '9'){
   sumX += 9.0;
  }else if(x == '0'){
   sumX += 0.0 ;
  }else{
   sumX += 10.0;
  }

 }

 char y;
 float sum_y;
 for(i = 0;i < 3; i++){
  scanf("%s", &y);
  if(y == 'A'){
   sum_y += 1.0;
  }else if((y == 'J') || (y == 'Q') || (y == 'K')){
   sum_y += 0.5 ;
  }else if(y == '2'){
   sum_y += 2.0;
  }else if(y == '3'){
   sum_y += 3.0;
  }else if(y == '4'){
   sum_y += 4.0;
  }else if(y == '5'){
   sum_y += 5.0;
  }else if(y == '6'){
   sum_y += 6.0;
  }else if(y == '7'){
   sum_y += 7.0;
  }else if(y == '8'){
   sum_y += 8.0;
  }else if(y == '9'){
   sum_y += 9.0;
  }else if(y == '0'){
   sum_y += 0.0;
  }else{
   sum_y += 10.0;
  }
 }

 if(sumX > 10.5){
  sumX = 0 ;
  printf("%.1f\n", sumX);
 }else{
  printf("%.1f\n", sumX);
 }

 if(sum_y > 10.5){
  sum_y = 0 ;
  printf("%.1f\n", sum_y);
 }else{
  printf("%.1f\n", sum_y);
 }

 if((sumX < sum_y) && (sum_y <= 10.5)){
  printf("B wins.\n");
 }else if((sumX > sum_y) && (sumX <= 10.5)){
  printf("A wins.\n");
 }else if(sumX == sum_y){
  printf("It's a tie.\n");
 }
 return 0 ;
}
