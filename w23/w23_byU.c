#include <stdio.h>
#include <math.h>
#define f1(a, x) (sqrt(a - x * x))


double f2(double a, double x) {
    double res = 0;
    res = (a * x * x * x + 7 * x) / sqrt(a + x);
    return res < 0 ? -res : res;
}



double f1x() {
    int err;
    double a, p, q;
    scanf("\n%lf %lf %lf %d", &a, &p, &q, &err);
    unsigned long long int n = 1, i = 0;
    double dx = 0, sum1 = 0, sum2 = 0, x = 0, curr = 0, temp = 0;

    for (n; n > 0; n *= 2) {
        dx = (q - p) / n;
        /*for (x = p; x < q; x = (n * x + q - p) / n) {
            sum2 += (q - p) * (f1(a, x) + f1(a, (n * x + q - p) / n)) / (2 * n);
        }*/
        curr = p + dx;
        temp = f1(a, p) + f1(a, q);
        for(curr=p+dx; curr<q; curr+=dx){
            temp+=f1(a,curr)*2;
        }
        /*
        for (i = 0; i < n - 1; i++) {   ///§U±Ð­ìª©
            temp += f1(a, curr) * 2;
            curr += dx;
        }*/
        sum2 = (q - p) / (2 * n) * temp;
        if (sum2 - sum1 <= pow(10, -err) && sum2 - sum1 > 0) {
            return sum2;
        } else {
            sum1 = sum2;
            sum2 = 0;
        }
    }
}



double f2x() {
    int err;
    double a, p, q;
    scanf("\n%lf %lf %lf %d", &a, &p, &q, &err);
    unsigned long long int n = 1, i = 0;
    double dx = 0, sum1 = 0, sum2 = 0, x = 0, curr = 0, temp = 0;

    for (n; n > 0; n *= 2) {
        dx = (q - p) / n;
        /*for (x = p; x < q; x = (n * x + q - p) / n) {
            sum2 += (q - p) * (f2(a, x) + f2(a, (n * x + q - p) / n)) / (2 * n);
        }*/
        curr = p + dx;
        temp = f2(a, p) + f2(a, q);
        for (i = 0; i < n - 1; i++) {
            temp += f2(a, curr) * 2;
            curr += dx;
        }
        sum2 = (q - p) / (2 * n) * temp;
        if ((sum2 - sum1 <= pow(10, -err) && sum2 - sum1 > 0)  || (sum1 - sum2 <= pow(10, -err) && sum1 - sum2 > 0)) {
            return sum2;
        } else {
            sum1 = sum2;
            sum2 = 0;
        }
    }
}



int main() {
    int choose_func = 0;
    scanf("%d", &choose_func);
    while (choose_func) {
        if (choose_func == 1) {
            printf("%.12f\n", f1x());
        } else if (choose_func == 2) {
            printf("%.12f\n", f2x());
        }
        scanf("%d", &choose_func);
    }
}
