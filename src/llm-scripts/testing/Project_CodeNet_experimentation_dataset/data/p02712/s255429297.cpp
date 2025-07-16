///f. fizzbuzz sequence
#include <stdio.h>
#include <math.h>

int main()
{
    long long int n;
    scanf("%lld",&n);
    long long int d3,d5,d15;
    d3=n/3; d5=n/5; d15=n/15;

    long long sum = (n*(n+1)-3*d3*(d3+1)-5*d5*(d5+1)+15*d15*(d15+1))/2;
    printf("%lld",sum);
    return 0;
}