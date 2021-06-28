#include <stdio.h>
#include<stdlib.h>
int abc(int x,int y){
 int x1,y1,z;
 x1=abs(x);
 y1=abs(y);
 if(x1>y1)
    z=x1;
 else
    z=y1;
 while(1){
  if(x1%z==0&&y1%z==0)
     break;
  else
      z=z-1;
 }
    return z;
}


void reduction(int fz,int fm){
 int s=abc(fz,fm),d1,d2;
 fz=fz/s;
 fm=fm/s;
 if(fz==0){
  printf("0");
 }
 else if(fz==fm){
  d1=fz/fm;
  printf("%d",d1);
 }
 else if(fz>fm){
  d1=(fz%fm);
  d2=(fz-d1)/fm;
  if(d1==0){
   printf("%d",d2);
  }
  else if((d2 == 0) && (d1 <0) && (fm < 0)){
   printf("%d/%d",abs(d1),abs(fm));
  }
  else{
     printf("%d(%d/%d)",d2,d1,fm);
  }
 }
 else if((fz < 0) && (fm < 0)){
  if(abs(fm) == 1){
    printf("%d",abs(fz));
  }
  else{
   printf("%d/%d",abs(fz),abs(fm));
  }

 }
 else if(fm == 1){
  printf("%d", fz);
 }
    else{
     printf("%d/%d",fz,fm);
 }
}


int equation(int x1,int y1,int x2, int y2){
 int m_n,m_d, b_n,b_d, temp;
 m_n = (y1-y2);
 m_d = (x1-x2);

 if(((m_n/m_d) == 1) && ((m_n%m_d) == 0) ){
  printf("y=") ;

  printf("x");
  b_n = x2*y1-x1*y2;
  b_d = (x2-x1) ;
  if(((b_n > 0) && (b_d > 0)) || ((b_n < 0) && (b_d < 0)) ){
   printf("+");
   reduction(b_n, b_d);
   printf("\n");
   return 0;
  }
  else if(b_n == 0){
   printf("\n");
   return 0;
  }
  reduction(b_n, b_d);
  printf("\n");
  return 0;
 }else if(((m_n/m_d) == -1) && ((m_n%m_d) == 0) ){
  printf("y=") ;

  printf("-x");
  b_n = x2*y1-x1*y2;
  b_d = (x2-x1) ;
  if(((b_n > 0) && (b_d > 0)) || ((b_n < 0) && (b_d < 0)) ){
   printf("+");
  }
  else if(b_n == 0){
   printf("\n");
   return 0;
  }
  reduction(b_n, b_d);
  printf("\n");
  return 0;
 }

 if(((b_n > 0) && (b_d > 0)) || ((b_n < 0) && (b_d < 0)) ){
  printf("y=") ;
  reduction(m_n, m_d);
  printf("x");
  b_n = x2*y1-x1*y2;
  b_d = (x2-x1) ;
  if(b_n == 0){
   printf("\n");
   return 0 ;
  }
  printf("+");
  reduction(b_n, b_d);
  printf("\n");
  return 0 ;
 }
 else if((x2*y1-x1*y2) == 0){
  printf("y=") ;
  reduction(m_n, m_d);
  printf("x");
  printf("\n");
  return 0 ;
 }
 else{
  printf("y=") ;
  reduction(m_n, m_d);
  printf("x");
  b_n = x2*y1-x1*y2;
  b_d = (x2-x1) ;
  if(b_n == 0){
   printf("\n");
   return 0;
  }
  if(((b_n > 0) && (b_d > 0)) || ((b_n < 0) && (b_d < 0)) ){
   printf("+");
  }
  reduction(b_n, b_d);
  printf("\n");
  return 0;
 }


}
int main(){
 int x1, y1, x2, y2;
 char n ;
 scanf("%d%c%d",&x1, &n, &y1);
 scanf("%d%c%d",&x2, &n, &y2);
 equation(x1, y1,x2,y2);


 return 0;

}
