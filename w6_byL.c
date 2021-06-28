#include<stdio.h>

double type_one(int in_net_voice,int out_net_voice,int local_calls,int in_letter,int out_letter){
 double cost ;
 cost = in_net_voice * 0.08 + out_net_voice * 0.1393 + local_calls * 0.1349 + in_letter * 1.1287 + out_letter * 1.4803 ;
 if(cost < 183){
  cost = 183 ;
 }
 return cost ;
}

double type_two(int in_net_voice,int out_net_voice,int local_calls,int in_letter,int out_letter){
 double cost ;
 cost = in_net_voice * 0.07 + out_net_voice * 0.1304 + local_calls * 0.1217 + in_letter * 1.1127 + out_letter * 1.2458 ;
 if(cost < 383){
  cost = 383 ;
 }
 return cost ;
}

double type_three(int in_net_voice,int out_net_voice,int local_calls,int in_letter,int out_letter){
 double cost ;
 cost = in_net_voice * 0.06 + out_net_voice * 0.1087 + local_calls * 0.1018 + in_letter * 0.9572 + out_letter * 1.1243 ;
 if(cost < 983){
  cost = 983 ;
 }
 return cost ;
}

void best_choice(double type_one, double type_two, double type_three){
 if( (type_one < type_two) && (type_one < type_three)){
  printf("183\n");
 }
 if( (type_two < type_one) && (type_two < type_three)){
  printf("383\n");
 }
 if( (type_three < type_two) && (type_three < type_one)){
  printf("983\n");
 }
 return 0 ;
}
int main(){

 int inNetVoice, outNetVoice, local_calls, in_letter, out_letter ;
 int one, two, three ;
 scanf("%d", &inNetVoice);
 scanf("%d", &outNetVoice);
 scanf("%d", &local_calls);
 scanf("%d", &in_letter);
 scanf("%d", &out_letter);

 one = type_one(inNetVoice, outNetVoice, local_calls, in_letter, out_letter);
 two = type_two(inNetVoice, outNetVoice, local_calls, in_letter, out_letter);
 three = type_three(inNetVoice, outNetVoice, local_calls, in_letter, out_letter);

 best_choice(one, two ,three);

 return 0 ;
}
