#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*Util functions*/

/*start the timer*/
time_t tick()
{
    time_t start;
    start = 1000 * time(NULL);
    return start;
}
/*get time difference in milliseconds*/
float tock(time_t start)
{
    time_t end;
    end = 1000 * time(NULL);
    float diff = difftime(end, start);
    return ((diff * 1000000) / CLOCKS_PER_SEC);
}
unsigned int sizeOfBinStr(const unsigned int n)
{
    return (n) ? ceil(log2(n + 1)) : 1;
}
void uint2bin(unsigned int n, char *nstr)
{
    unsigned int size = ceil(log2(n + 1));

    for (int i = size - 1; i >= 0; i--)
    {
        if (n >= pow(2, i))
        {
            nstr[size - 1 - i] = '1';
            n -= pow(2, i);
        }
        else
        {
            nstr[size - 1 - i] = '0';
        }
    }

    return;
}

/*fast exponentiation*/
int naive1(int a, int b, int m)
{
    int c = 1;
    for (int i = 0; i < b; i++)
    {
        c *= a;
        c %= m;
    }
    return c;
}

int naive2(int a, int b, int m)
{
    int c = 1;
    for (int i = 0; i < b; i++)
    {
        c = c * a % m;
    }
    return c;
}

int algo5itr(const int base, char exp[], const unsigned int m, const unsigned int sizeOfExp)
{
    int x = 1;
    int pow = base % m;
    for (int i = sizeOfExp - 1; i >= 0; i--)
    {
        if (exp[i] == '1')
        {
            x = x * pow % m;
        }
        pow = pow * pow % m;
    }
    return x;
}

int algo5rec(const int base, char exp[], const int m, const int sizeOfExp)
{
    /*base cases*/
    if (sizeOfExp <= 0)
        return 1;
    if (sizeOfExp == 1 && exp[sizeOfExp] == '1')
    {
        return base;
    }
    int x = algo5rec(base,exp,m,sizeOfExp-1);
    if(exp[sizeOfExp-1] == '0')
    {
        return (x*x) % m;
    }
    else
    {
        return (x*x*base) % m;
    }

}

/*Driver*/
int main()
{
    int base, exp, m, ans;
    time_t start;
    float duration;

    printf("Fast Exponentiation\n=====================================\n");
    printf("To calculate the expression: base^(exponent) mod m,\n");

    /*input from stdin*/
    printf("Enter the base : ");
    scanf("%d", &base);
    printf("Enter the exponent : ");
    scanf("%d", &exp);
    printf("Enter m : ");
    scanf("%d", &m);

    const unsigned int size = sizeOfBinStr(exp);
    char *expStr = (char *)malloc(size * sizeof(char));
    uint2bin(exp, expStr);

    printf("\nNaîve algorithm #1\n=====================================\n");

    /*naive1*/
    start = tick();
    ans = naive1(base, exp, m);
    duration = tock(start);

    printf("Answer = %d\nTime spent = %.3f milliseconds\n-------------------------------------\n", ans, duration);

    printf("\nNaîve algorithm #2\n=====================================\n");

    /*naive2*/
    start = tick();
    ans = naive2(base, exp, m);
    duration = tock(start);

    printf("Answer = %d\nTime spent = %.3f milliseconds\n-------------------------------------\n", ans, duration);

    printf("\nAlgorithm 5 iterative\n=====================================\n");

    /*Algorithm 5*/
    start = tick();
    ans = algo5itr(base, expStr, m, size);
    duration = tock(start);

    printf("Answer = %d\nTime spent = %.3f milliseconds\n-------------------------------------\n", ans, duration);

    printf("\nAlgorithm 5 recursive\n=====================================\n");

    /*Algorithm 5*/
    start = tick();
    ans = algo5rec(base, expStr, m, size);
    duration = tock(start);

    printf("Answer = %d\nTime spent = %.3f milliseconds\n-------------------------------------\n", ans, duration);
    free(expStr);
}