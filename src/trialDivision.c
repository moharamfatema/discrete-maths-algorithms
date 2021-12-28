#include <math.h>
#include <stdio.h>

short isPrime(unsigned int n)
{
    if (n <= 1)
        return -1;
    short prime = 1;
    int d = 2;
    while (prime && d <= sqrt(n))
    {
        if (n % d == 0)
        {
            prime = 0;
        }
        else
        {
            d++;
        }
    }
    return prime;
}
int main()
{
    int n = 0;
    short prime;

    printf("The trial division\n=====================================\n");
    printf("To determine whether a number n is prime:\n");

    while (n <= 1)
    {
        /*input from stdin*/
        printf("Enter n > 1 : ");
        scanf("%d", &n);
    }

    prime = isPrime(n);

    printf("n is %s.\n=====================================\n", (prime == 1)?"prime":"not prime");

}