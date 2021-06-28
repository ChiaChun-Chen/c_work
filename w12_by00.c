#include <stdio.h>
#include <math.h>

int gcd(int m, int n)
{
    if (n == 0)
        return m;
    else
        return gcd(n, m % n);
}
int lcm(int m, int n)
{
    return m * n / gcd(m, n);
}

int operate(int *n1, int *d1, int *n2, int *d2, char *op, int *n_ans, int *d_ans, int *f_ans)
{
    switch (*op)
    {
    case '+':
        *d_ans = lcm(*d1, *d2);
        *n_ans = ((*d_ans / *d1) * (*n1)) + ((*d_ans / *d2) * (*n2));
        break;
    case '-':
        *d_ans = lcm(*d1, *d2);
        *n_ans = ((fabs(*d_ans) / *d1) * (*n1)) - ((fabs(*d_ans) / *d2) * (*n2));
        break;
    case '*':
        *n_ans = (*n1) * (*n2);
        *d_ans = (*d1) * (*d2);
        break;
    case '/':
        if (*n2 > 0)
        {
            *n_ans = (*n1) * (*d2);
            *d_ans = (*d1) * (*n2);
        }
        else
        {
            *n_ans = -((*n1) * (*d2));
            *d_ans = (*d1) * fabs(*n2);
        }
        break;
    default:
        return 1;
        break;
    }
    //程虏て
    int rem = 0;
    rem = gcd(fabs(*n_ans), fabs(*d_ans));
    *n_ans /= rem;
    *d_ans /= rem;
    //浪琩安だ计
    if (fabs(*n_ans) >= fabs(*d_ans))
    {
        *f_ans = *n_ans / *d_ans;
        *n_ans = *n_ans % *d_ans;
    }
    return 0;
}
int scan_fraction(int *nump, int *denomp)
{
    char slash; //character between numerator and denominator
    int status; //status code returned by scanf indicating number of valid obtained
    int error;  //flag indicating presence of an error
    //char discard; unprocessed character from input line
    error = 0; //no errors detected yet
    status = scanf("%d %c %d", nump, &slash, denomp);
    if (status < 3 || slash != '/' || *denomp <= 0)
    {
        error = 1;
    }
    return error;
}

int main()
{
    int n1 = 0, d1 = 0; //材だ计だだダ
    int n2 = 0, d2 = 0; //材だ计だだダ
    char op, again;
    int n_ans = 0, d_ans = 0, f_ans = 0; //氮だだダ
    int error1, error2, error3, error[20], i = 0, j = 0;
    int n_out[20] = {0}, d_out[20] = {0}, f_out[20] = {0};
    do
    {
        n_ans = 0, d_ans = 0, f_ans = 0, error3 = 0;
        error1 = scan_fraction(&n1, &d1);
        error2 = scan_fraction(&n2, &d2);
        scanf(" %c", &op);
        scanf(" %c", &again);
        if (error1 != 1 && error2 != 1)
        {
            error3 = operate(&n1, &d1, &n2, &d2, &op, &n_ans, &d_ans, &f_ans);
            n_out[i] = n_ans;
            d_out[i] = d_ans;
            f_out[i] = f_ans;
            error[i] = error3;
        }
        else
            error[i] = 1;

        i++;
        getchar();
    } while (again == 'y' && again != 'n');
    for (j = 0; j < i; j++)
    {
        if (error[j] != 1)
        {
            if (!f_out[j])
            {
                if (n_out[j])
                    printf("%d%c%d\n", n_out[j], '/', d_out[j]);
                else
                    printf("0\n");
            }
            else
            {
                if (n_out[j] != 0)
                    printf("%d%c%d%c%d%c\n", f_out[j], '(', n_out[j], '/', d_out[j], ')');
                else
                    printf("%d\n", f_out[j]);
            }
        }
        else
            printf("ERROR\n");
    }

    return 0;
}
