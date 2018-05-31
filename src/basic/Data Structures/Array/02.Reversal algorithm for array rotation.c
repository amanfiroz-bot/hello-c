// Reversal algorithm for array rotation

#include <stdio.h>


void
leftRotate2(int arylst[], int d, int n)
{
    int i, j, temp;

    for (i = 0; i < d; i++)
    {
        temp = arylst[0];
        for (j = 0; j < n - 1; j++)
        {
            arylst[j] = arylst[j + 1];
        }
        arylst[j] = temp;
    }
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

void
leftRotate3(int arylst[], int d, int n)
{
    // A Juggling Algorithm
    int i, j, k, temp;

    for (i = 0; i < gcd(d, n); i++)
    {
        temp = arylst[i];
        j = i;
        while (1)
        {
            k = j + d;
            if (k >= n)
                k = k - n;

            if (k == i)
                break;

            arylst[j] = arylst[k];
            j = k;
        }
        arylst[j] = temp;
    }
}

void
revreseAry(int arylst[], int start, int end)
{
    int temp;

    while (start < end)
    {
        temp = arylst[start];
        arylst[start] = arylst[end];
        arylst[end] = temp;

        start++;
        end--;
    }
}

void
leftRotate4(int arylst[], int d, int n)
{
    revreseAry(arylst, 0, d-1);
    revreseAry(arylst, d, n-1);
    revreseAry(arylst, 0, n-1);
}

void printAry(int *arylst, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d ", arylst[i]);
    }
}

int
main(int argc, const char *argv[])
{
    int arylst[] = {1, 2, 3, 4, 5, 6, 7};
    int arylen;

    arylen = sizeof(arylst) / sizeof(*arylst);
    leftRotate4(arylst, 2, arylen);

    printAry(arylst, arylen);

    return 0;
}


// https://www.geeksforgeeks.org/program-for-array-rotation-continued-reversal-algorithm/