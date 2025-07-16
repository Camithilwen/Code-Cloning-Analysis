#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    long long sum=3;
    scanf("%d",&n);
    if(n==1) sum=1;
    else if(n==2) sum=2;
    else
        {
           while(n>2)
           {
               if(n%3!=0&&n%5!=0)
                 sum+=n;
               n--;
           }
        }
        printf("%lld",sum);
    return 0;
}
