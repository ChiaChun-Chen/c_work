//work 1
/*==========================================================

//lab202

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

using namespace std;


int gpio_export(unsigned int gpio){
        int fd , len;
        char buf[64];

        fd = open("/sys/class/gpio/export", O_WRONLY);
        if(fd < 0){
                perror("gpio/export");
                return fd ;
        }
        len = snprintf(buf, sizeof(buf),"%d",gpio);
        write(fd, buf, len);
        close(fd);
        return 0;
}

int gpio_unexport(unsigned int gpio){
        int fd , len;
        char buf[64];

        fd = open("/sys/class/gpio/unexport", O_WRONLY);
        if(fd < 0){
                perror("gpio/export");
                return fd ;
        }
        len = snprintf(buf, sizeof(buf),"%d",gpio);
        write(fd, buf, len);
        close(fd);
        return 0;
}

int gpio_set_dir(unsigned int gpio, string dirStatus){
        int fd ;
        char buf[64];

        snprintf(buf, sizeof(buf), "/sys/class/gpio/gpio%d/direction",gpio);
        fd = open(buf, O_WRONLY);
        if(fd < 0){
                perror("gpio/direction");
                return fd ;
        }
        if(dirStatus == "out"){
                write(fd, "out", 4);
        }else{
                write(fd, "in", 3);
        }

        close(fd);
        return 0;
}

int gpio_set_value(unsigned int gpio, int value){
        int fd ;
        char buf[64];

        snprintf(buf, sizeof(buf), "/sys/class/gpio/gpio%d/value",gpio);
        fd = open(buf, O_WRONLY);
        if(fd < 0){
                perror("gpio/set-value");
                return fd ;
        }
        if(value == 0){
                write(fd, "0", 2);
        }else{
                write(fd, "1", 2);
        }

        close(fd);
        return 0;
}

int main(){
        string input_led, input;
        int n;
        cin>>n;
        for(int i=0; i<n*2; i++){
            if(i%2==0){
                gpio_set_dir(396, "out");
                gpio_set_value(396, 1);
                gpio_set_dir(255, "out");
                gpio_set_value(255, 1);
                gpio_set_dir(428, "out");
                gpio_set_value(428, 0);
                gpio_set_dir(389, "out");
                gpio_set_value(389, 0);
            }
            else{
                gpio_set_dir(396, "out");
                gpio_set_value(396, 0);
                gpio_set_dir(255, "out");
                gpio_set_value(255, 0);
                gpio_set_dir(428, "out");
                gpio_set_value(428, 1);
                gpio_set_dir(389, "out");
                gpio_set_value(389, 1);
            }
                sleep(1);
        }
        gpio_set_dir(428, "out");
        gpio_set_value(428, 0);
        gpio_set_dir(389, "out");
        gpio_set_value(389, 0);
return 0;
}
        /*cout <<"input led1~led4"<<endl;
        cin >> input_led;
        if(input_led == "led1"){
                gpio_export(396);
                cout <<"input on or off"<<endl;
                cin >> input;
                if(input == "on"){
                    gpio_set_dir(396, "out");
                    gpio_set_value(396, 1);
		    sleep(0.5);
                }else if(input == "off"){
                    gpio_set_value(396, 0);
                    gpio_unexport(396);
            }
        }



        if(input_led == "led2"){
                gpio_export(255);
                cin >> input;
                if(input == "on"){
                    gpio_set_dir(255, "out");
                    gpio_set_value(255, 1);
                }else if(input == "off"){
                    gpio_set_value(255, 0);
                    gpio_unexport(255);
            }
        }

        if(input_led == "led3"){
                gpio_export(428);
                cin >> input;
                if(input == "on"){
                    gpio_set_dir(428, "out");
                    gpio_set_value(428, 1);
                }else if(input == "off"){
                    gpio_set_value(428, 0);
                    gpio_unexport(428);
            }
        }

        if(input_led == "led4"){
                gpio_export(389);
                cin >> input;
                if(input == "on"){
                    gpio_set_dir(389, "out");
                    gpio_set_value(389, 1);
                }else if(input == "off"){
                    gpio_set_value(389, 0);
                    gpio_unexport(389);
            }
        }

        return 0 ;
}
==========================================================*/
/*=========================================================

//lab2
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

using namespace std;
int gpio_export(unsigned int gpio){
        int fd , len;
        char buf[64];

        fd = open("/sys/class/gpio/export", O_WRONLY);
        if(fd < 0){
                perror("gpio/export");
                return fd ;
        }
        len = snprintf(buf, sizeof(buf),"%d",gpio);
        write(fd, buf, len);
        close(fd);
        return 0;
}

int gpio_unexport(unsigned int gpio){
        int fd , len;
        char buf[64];

        fd = open("/sys/class/gpio/unexport", O_WRONLY);
        if(fd < 0){
                perror("gpio/export");
                return fd ;
        }
        len = snprintf(buf, sizeof(buf),"%d",gpio);
        write(fd, buf, len);
        close(fd);
        return 0;
}

int gpio_set_dir(unsigned int gpio, string dirStatus){
        int fd ;
        char buf[64];

        snprintf(buf, sizeof(buf), "/sys/class/gpio/gpio%d/direction",gpio);
        fd = open(buf, O_WRONLY);
        if(fd < 0){
                perror("gpio/direction");
                return fd ;
        }
        if(dirStatus == "out"){
                write(fd, "out", 4);
        }else{
                write(fd, "in", 3);
        }

        close(fd);
        return 0;
}

int gpio_set_value(unsigned int gpio, int value){
        int fd ;
        char buf[64];

        snprintf(buf, sizeof(buf), "/sys/class/gpio/gpio%d/value",gpio);
        fd = open(buf, O_WRONLY);
        if(fd < 0){
                perror("gpio/set-value");
                return fd ;
        }
        if(value == 0){
                write(fd, "0", 2);
        }else{
                write(fd, "1", 2);
        }

        close(fd);
        return 0;
}

int main(){
        string input_led, input;
        cout <<"input led1~led4"<<endl;
        cin >> input_led;
        if(input_led == "led1"){
                gpio_export(396);
                cout <<"input on or off"<<endl;
                cin >> input;
                if(input == "on"){
                    gpio_set_dir(396, "out");
                    gpio_set_value(396, 1);
                }else if(input == "off"){
                    gpio_set_value(396, 0);
                    gpio_unexport(396);
            }
        }

        if(input_led == "led2"){
                gpio_export(255);
                cin >> input;
                if(input == "on"){
                    gpio_set_dir(255, "out");
                    gpio_set_value(255, 1);
                }else if(input == "off"){
                    gpio_set_value(255, 0);
                    gpio_unexport(255);
            }
        }

        if(input_led == "led3"){
                gpio_export(428);
                cin >> input;
                if(input == "on"){
                    gpio_set_dir(428, "out");
                    gpio_set_value(428, 1);
                }else if(input == "off"){
                    gpio_set_value(428, 0);
                    gpio_unexport(428);
            }
        }

        if(input_led == "led4"){
                gpio_export(389);
                cin >> input;
                if(input == "on"){
                    gpio_set_dir(389, "out");
                    gpio_set_value(389, 1);
                }else if(input == "off"){
                    gpio_set_value(389, 0);
                    gpio_unexport(389);
            }
        }

        return 0 ;
}
==========================================================*/


/*==========================================================
??????????????????I
??????????????????IC???????????????????????????????????????
??????m ???????????? 8 ??????????????????????????? 4 ??????
??????????????? 00000000 ??? 11111111 (????????? 0~255)
??????????????? :
C(m) = m if m = 0 or m = 1 (?????????)
C(m) = C(m/2) if m ??????(?????????)
C(m) = C((m+1)/2) if m ??????(?????????)
??? :
m=00001010(????????? 10)???????????????????????????????????? 5, 3, 2, 1
C(10)= C(5)=C(3)=C(2)=C(1)=1???????????? 4 ???
?????????????????????????????????????????????
R(m) = [C(m) ???????????????]????????? R(10) = 4
?????????IC????????????m=00001010(????????? 10) ????????????????????????????????????4???????????????IC????????? 0100 (????????? 4)

-------------
???????????? :
????????? 8 bit ??????
???????????????????????????????????????
??????????????? 0 ??????????????????
???????????????????????????????????????
....
?????? -1 ??????

-------------
???????????? :
????????? 4 bit ??????
?????????????????????????????????????????????

-------------
Sample Input:
00000000
0
11111111
0
00000001
0
10000000
0
00111111
-1
-------------
Sample Output:
0000
1000
0000
0111
0110

-------------
Sample Input:
00001010
0
01100100
-1
-------------
Sample Output:
0100
0111
==============================================================*/
//w10
#include "stdio.h"

int change_from_2_to_10(int m_8) {
	int temp, sum=0, i, j;
	for(i=0; m_8>0; i++){
        temp=m_8%10;

        m_8=m_8/10;
        for(j=0; j<i; j++){
            if(temp==0){break;}
            temp=temp*2;
            //printf("###############%d\n", temp);
        }
        sum=sum+temp;
        //printf("@@@@@@@@@@@@@%d\n", sum);
	}
	return sum;
}

void change_from_10_to_2(int m, int *num){
    int i, j;
    for(i=0; m>0; i++){
        num[i]=m%2;
        m=m/2;
    }
    for(j=3; j>=0; j--){
        printf("%d", num[j]);
    }
}

int countR(int m){
    int i=0;
    for(i=0; m>=0; i++){
        if(m==0||m==1) return i;
        else if(m%2==0){
            //printf("...........%d", m);
            m=m/2;
        }
        else{
            m=(m+1)/2;
        }
    }
}

int main() {
	int m_8, m, flag, ans;
	do{
        int num[4]={0};
        scanf("%d", &m_8);
        scanf("%d", &flag);
        m=change_from_2_to_10(m_8);
        ans=countR(m);
        //printf("%d\n", ans);
        change_from_10_to_2(ans, &num);
        printf("\n");
	}while(flag==0);
}
