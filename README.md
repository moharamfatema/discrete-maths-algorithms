
# Discrete Mathematics For Computing | Project
Implementing common algorithms in discrete maths with **C**.

---
## Data Structures 
All algorithms use dynamically allocated arrays when they need a list.
Only the ``main`` function is responsible for allocation and deallocation.

## Design assumptions
 All numbers are non-negative integers.

## - Problem 1: Fast Exponentiation

>$base^{exp} \bmod m$
>
> using 2 naîve algorithms and *algorithm 5*
> ### sample runs:
> ![run1](/img/fastexp1.png)
>
> ---
>
> ![run2](/img/fastexp2.png)
> As it is stated in the previous sample runs:
> Both naîve algorithms take extremely big amounts of time to finish, compared to both implementations of algorithm 5, which take less than a millisecond.
>
> ---
>
> ### Overflows
>
> Algorithm 5 breaks (overflows) when the number of bits representing the exponent gets large, for example:
> In the following sample run: the number of bits = 30
> ![break](/img/fastexpbreak2.png)
## - problem 2:

> List all prime numbers before *n*  
> The Sieve Of Eratosthenes  
> ## Sample runs  
> ![run2](/img/sieve2.png)
> ![run1pt1](/img/sieve1.png)
> ![run1pt2](/img/sieve1-2.png)
> 
> ## Pseudo code 
>```
> theSieve(int n ):  
>    let `smallList` be a new array = {2,3,5,7}  
>    let  list  be a new list [0..n-1]  
>    let  i  = 0  
>
>    /*to fill in the initial prime numbers before >10 */  
>
>    while  it  < 4 AND  smallList[it] < n   
>        list[it]  =  smallList[it]   
>        it  =  it  + 1  
>
>    /*checking whether the condition of n < the >initial 4 numbers held  */
>    if  it  < 4    
>        return list[0..it]   
>        /*if the condition didn't hold return list up to n  */  
>    
>    bool  notprime    
>    for  i  = 8 to  n   
>        notprime = false  
>        
>        for each j in list[0..it]  
>        
>            if i is divisible by j  
>                notprime = true  
>                break  
>        
>        if NOT notprime  
>            insert i in list  
>            it = it + 1  
>    
>    return list[0..it]
>```


## - problem 3:

Trial division to determine whether *n* is *prime*.  
## Sample runs
![run1]()