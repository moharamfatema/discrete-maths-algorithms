#include <time.h>
#include <math.h>

/*Timer functions*/
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

int naive1(int a, int b, int m)
{
    int c = 1;
    for (int i = 0; i < b; i++)
    {
        c = c * a % m;
    }
    return c;
}
char * int2bin(unsigned int n)
{
    char * n = (char *)malloc(ceil(log2(n)) * sizeof(char));
    
}

int algo5(int b, char a[], unsigned int m, const unsigned int k)
{
    int x = 1;
    int pow = b % m;
    for (int i = 0; i < k; i++)
    {
        if (a[i] == 1)
        {
            x = x * pow % m;
        }
        pow = pow * pow % m;
    }
    return x;
}