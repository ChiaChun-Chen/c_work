#include <stdio.h>

void check(char x[4], char y[4], int *A, int *B)
{
    char temp[4] = {x[0], x[1], x[2], x[3]};
    for (int i = 0; i < 4; i++)
    {
        if (x[i] == y[i])
        {
            (*A)++;
            x[i] = 'N';
            y[i] = 'n';
        }
    }
    //printf("%c%c%c%c ", x[0], x[1], x[2], x[3]);
    //printf("%c%c%c%c\n", y[0], y[1], y[2], y[3]);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (x[i] == y[j])
            {
                (*B)++;
                x[i] = 'M';
                y[j] = 'm';
                break;
            }
        }
    }
    x[0] = temp[0];
    x[1] = temp[1];
    x[2] = temp[2];
    x[3] = temp[3];
    //printf("%c%c%c%c ", x[0], x[1], x[2], x[3]);
    //printf("%c%c%c%c\n", y[0], y[1], y[2], y[3]);
}

int main()
{
    int A[6] = {0, 0, 0, 0, 0, 0}, B[6] = {0, 0, 0, 0, 0, 0}, index = 0;
    char x[4], y[4];
    scanf("%c%c%c%c", &x[0], &x[1], &x[2], &x[3]);
    do
    {
        getchar();
        scanf(" %c", &y[0]);
        scanf(" %c", &y[1]);
        scanf(" %c", &y[2]);
        scanf(" %c", &y[3]);
        check(x, y, &A[index], &B[index]);
        index++;
        if (A[index - 1] == 4)
            break;

    } while (index <= 5);
    for (int j = 0; j < index; j++)
    {
        if (A[j] == 4)
            printf("win\n");
        else
            printf("%dA%dB\n", A[j], B[j]);
    }
    return 0;
}
