#include <stdio.h>
int main()
{
    int m, n = 0, ntemp = 0, count = 0, size = 0, out = 0;
    scanf("%d", &n);
    ntemp = n;
    while (ntemp != 0)
    {
        ntemp /= 10;
        ++size;
    }
    int arr[size];
    scanf("%d", &m);
    int marr[m];
    int i = 0;
    do
    {
        arr[i] = n % 10;
        n = n / 10;
        i++;
    } while (n >= 1);

    for (int i = 0; i <= size - m; i++)
    {
        out = 0;
        for (int k = 0; k < m; k++)
        {
            marr[k] = arr[i + k];
        }
        for (int j = 0; j < m; j++)
        {
            for (int p = 1; p < m; p++)
            {
                if (marr[j] == marr[(j + p) % m])
                {
                    out = 1;
                    break;
                }
            }
            if (out != 0)
                break;
            else if (j == m - 1)
                count++;
        }
    }
    printf("%d\n", count);
}
