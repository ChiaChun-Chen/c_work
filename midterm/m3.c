//midterm3
//皚龟暗疊翴计笲衡

/*
SampleInput:
-4964658486415446456.41564657844548181
-4656746465456451144.45641189184856484
======================================
-1234567890123456789.12345678901234567
-1234567890123456789.12345678901234567
SampleOutput:
-9621404951871897600.87205847029404665
-307912020958995311.95923468659691697
23119155858813504855269906941333916997.1321073964785829456433404308255604
=========================================================================
-2469135780246913578.24691357802469134
0
1524157875323883675323883573814967234.0437435343057460945526596755677489
*/
#include <stdio.h>
#include <string.h>
#define MAX 40
void change_char_to_int(char *A, int *r, int *f, int *is_minus, int *len_r, int *len_f){
    *len_r=0;*len_f=0;
    int i=MAX-1;
    for(i; i>0&&A[i]=='0'; i--)continue;
    for(int j=0; i>=0; j++){
        if(A[i]==NULL){    //σ納enter
            i--;j--;continue;
        }
        if(A[i]=='.'){      //跋だ龟计计
            i--;break;
        }
        f[j]=A[i]-'0';      //锣计
        printf("%d, ", f[j]);
        i--;(*len_f)++;
    }
    printf("\n");
    for(int j=0; i>=0; j++){    //龟计场だ
        if(A[i]=='-'){
            i--;*is_minus=1;continue;
        }
        r[j]=A[i]-'0';
        printf("%d", r[j]);
        i--;(*len_r)++;
    }
    printf("\n");
}

void initializer_list(char *A){
    for(int i=0; i<MAX; i++){
        A[i]='0';
    }
}
void initializer_int(int *a){
    for(int i=0; i<MAX; i++){
        a[i]=0;
    }
}

void add(int *a, int *b, int *c, int *carry){
    int i=0;
    for(i=0; i<MAX; i++){
        c[i]=a[i]+b[i]+*carry;
        if(c[i]>9){
            c[i]-=10;
            *carry=1;
        }else{
            *carry=0;
        }
        //printf("-------%d\n", c[i]);
    }
}

void minus(int *a, int *b, int *c, int *borrow, int len){
    int i=0;
    for(i=0; i<len; i++){
        c[i]=a[i]-b[i]-*borrow;
        if(c[i]<0){
            c[i]+=10;
            *borrow=1;
        }else{
            *borrow=0;
        }
    }
}

void multiply(int *a, int *b, int *c, int *carry, int len){
    int i=0, j=0;
    for(i; i<MAX; i++){
        j=0;
        //场だ
        for(j; j<MAX; j++){
            c[i+j]=a[i]*b[j]+c[i+j]+*carry;
            if(c[i+j]>9){
                *carry=c[i+j]/10;
                c[i+j]%=10;
            }else{
                *carry=0;
            }
        }
        //carry秈场だ
        c[i+j]+=(*carry);
        *carry=0;
        printf("...............");
        for(int k=0; k<MAX; k++){
            printf("%d", c[k]);
        }printf("\n");
        //printf("i=%d, j=%d, c[i+j]=%d\n", i, j, c[0]);
    }
}

void my_print(int *r, int *f, int *carry){
    int i=0;
    if(*carry==0){
        for(i=MAX-1; r[i]==0; i--)continue;
        for(i; i>=0; i--){
            printf("%d", r[i]);
        }
        printf(".");
        for(i=MAX-1; f[i]==0; i--)continue;
        for(i; i>=0; i--){
            printf("%d", f[i]);
        }
    }else{
        printf("%d", *carry);
        for(i=MAX-1; r[i]==0; i--)continue;
        for(i; i>=0; i--){
            printf("%d", r[i]);
        }
        printf(".");
        for(i=MAX-1; f[i]==0; i--)continue;
        for(i; i>=0; i--){
            printf("%d", f[i]);
        }
    }
}

int compare(int *a, int *b){
    int i=MAX-1;
    for(i; i>=0; i--){
        if(a[i]>b[i]) return 1;
        if(b[i]>a[i]) return -1;
    }
    return 0;
}

int main(){
    char a[MAX], b[MAX], space;
    int ar[MAX], af[MAX], br[MAX], bf[MAX], cr[MAX], cf[MAX], ma[2*MAX], mb[2*MAX], mc[2*MAX];
    int is_minus_a=0, is_minus_b=0, carry=0, order=0, len_r=0, len_f=0;

    initializer_list(a);
    initializer_list(b);
    initializer_int(cr);initializer_int(cf);
    initializer_int(ar);initializer_int(af);
    initializer_int(br);initializer_int(bf);
    scanf("%s", a);scanf("%s", b);

    change_char_to_int(a, ar, af, &is_minus_a, &len_r, &len_f);
    change_char_to_int(b, br, bf, &is_minus_b, &len_r, &len_f);//р计だ秈だだダ锣

    switch(is_minus_a){
    case 0:
        if(is_minus_b==0){
            //add(a,b)
            add(af,bf,cf,&carry);
            add(ar,br,cr,&carry);
            printf("\n");
            my_print(cr, cf, &carry);
            //minus(a,b);
            carry=0;
            order=compare(ar, br);
            if(order==1){
                //minus(a,b)
                minus(af,bf,cf,&carry, len_f);
                minus(ar,br,cr,&carry, len_r);
                printf("\n");
                printf("len_r=%d, len_f=%d\n", len_r, len_f);
                my_print(cr,cf,&carry);
            }else if(order==0){
                printf("\n0");
            }else{
                //minus(b,a)
                minus(bf,af,cf,&carry, len_f);
                minus(br,ar,cr,&carry, len_r);
                printf("\n");
                printf("len_r=%d, len_f=%d\n", len_r, len_f);
                printf("-");
                my_print(cr,cf,&carry);
            }
            //multiply(a,b)
            initializer_int(cr);initializer_int(cf);carry=0;
            multiply(af,bf,cf,&carry, len_f);
            multiply(ar,br,cr,&carry, len_r);
            printf("\n");
            my_print(cr, cf, &carry);
        }else{
            //add=>minus(a,b)
            carry=0;
            order=compare(ar, br);
            if(order==1){
                //minus(a,b)
                minus(af,bf,cf,&carry, len_f);
                minus(ar,br,cr,&carry, len_r);
                printf("\n");
                printf("len_r=%d, len_f=%d\n", len_r, len_f);
                my_print(cr,cf,&carry);
            }else if(order==0){
                printf("\n0");
            }else{
                //minus(b,a)
                minus(bf,af,cf,&carry, len_f);
                minus(br,ar,cr,&carry, len_r);
                printf("\n");
                printf("len_r=%d, len_f=%d\n", len_r, len_f);
                printf("-");
                my_print(cr,cf,&carry);
            }
            //minus=>add(a,b)
            add(af,bf,cf,&carry);
            add(ar,br,cr,&carry);
            printf("\n");
            my_print(cr, cf, &carry);
            //multiply=>-multiply(a,b)
            initializer_int(cr);initializer_int(cf);carry=0;
            multiply(af,bf,cf,&carry, len_f);
            multiply(ar,br,cr,&carry, len_r);
            printf("\n-");
            my_print(cr, cf, &carry);
        }
        break;
    case 1:
        if(is_minus_b==0){
            //add=>minus(b,a)
            carry=0;
            order=compare(br, ar);
            if(order==1){
                //minus(b,a)
                minus(bf,af,cf,&carry, len_f);
                minus(br,ar,cr,&carry, len_r);
                printf("\n");
                printf("len_r=%d, len_f=%d\n", len_r, len_f);
                my_print(cr,cf,&carry);
            }else if(order==0){
                printf("\n0");
            }else{
                //minus(a,b)
                minus(af,bf,cf,&carry, len_f);
                minus(ar,br,cr,&carry, len_r);
                printf("\n");
                printf("len_r=%d, len_f=%d\n", len_r, len_f);
                printf("-");
                my_print(cr,cf,&carry);
            }
            //minus=>-add(a,b)
            add(af,bf,cf,&carry);
            add(ar,br,cr,&carry);
            printf("\n-");
            my_print(cr, cf, &carry);
            //multiply=>-multiply(a,b)
            initializer_int(cr);initializer_int(cf);carry=0;
            multiply(af,bf,cf,&carry, len_f);
            multiply(ar,br,cr,&carry, len_r);
            printf("\n-");
            my_print(cr, cf, &carry);
        }else{
            //add=>-add(a,b)
            add(af,bf,cf,&carry);
            add(ar,br,cr,&carry);
            printf("\n-");
            my_print(cr, cf, &carry);
            //minus=>minus(b,a)
            carry=0;
            order=compare(br, ar);
            if(order==1){
                //minus(b,a)
                minus(bf,af,cf,&carry, len_f);
                minus(br,ar,cr,&carry, len_r);
                printf("\n");
                printf("len_r=%d, len_f=%d\n", len_r, len_f);
                my_print(cr,cf,&carry);
            }else if(order==0){
                printf("\n0");
            }else{
                //minus(a,b)
                minus(af,bf,cf,&carry, len_f);
                minus(ar,br,cr,&carry, len_r);
                printf("\n");
                printf("len_r=%d, len_f=%d\n", len_r, len_f);
                printf("-");
                my_print(cr,cf,&carry);
            }
            //multiply(a,b)
            initializer_int(mc);initializer_int(ma);initializer_int(mb);
            carry=0;
            printf("\n");
            int m=2*MAX-1;int i;
            for(i=MAX-1; ar[i]==0; i--)continue;
            for(i; i>=0; i--){
                ma[m]=ar[i];
                m--;
            }
            for(i=MAX-1; af[i]==0; i--)continue;
            for(i; i>=0; i--){
                ma[m]=af[i];
                m--;
            }
            for(int l=0; l<2*MAX; l++){
                printf("%d,", ma[l]);
            }
        }
    }

}
