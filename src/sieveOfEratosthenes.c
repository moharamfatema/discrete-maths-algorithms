#include <stdlib.h>
#include <stdio.h>

int allPrimesBeforeN(int n, int *list)
{
    int it = 0;
    int smallList[] = {2, 3, 5, 7};
    while (it < 4 && smallList[it] < n)
    {
        list[it] = smallList[it];
        it++;
    }
    if (it < 4)
    {
        return it;
    }

    short notAprime = 0;
    for (int i = 8; i <= n; i++)
    {
        notAprime = 0;
        for (int j = 0; j < it; j++)
        {
            if (i % list[j] == 0)
            {
                notAprime = 1;
                break;
            }
        }
        if (!notAprime)
        {
            list[it++] = i;
        }
    }
    return it;
}
/*util*/
void printIntArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if(i % 4 == 0)printf("\n");
        printf("%d \t", arr[i]);
    }
    printf("\n");
}
int main()
{
    int n, it;

    printf("The Sieve of Eratosthenes\n=====================================\n");
    printf("To show a list of all prime numbers before n:\n");
    
    /*input from stdin*/
    printf("Enter n : ");
    scanf("%d",&n);

    int * list = (int *)malloc(n * sizeof(int));
    it = allPrimesBeforeN(n,list);

    printf("There are %d prime numbers before n\n=====================================\n",it);

    printIntArr(list,it);
    
    printf("\n=====================================\n");
}