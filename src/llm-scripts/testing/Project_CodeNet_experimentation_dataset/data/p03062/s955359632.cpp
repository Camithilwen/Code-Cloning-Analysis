#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n,k=0;
    long long sum=0;
    scanf("%d",&n);
    int num[100005];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
        if(num[i]<0)
        {
            num[i]=-num[i];
            k++;
        }
        sum+=num[i];
    }
    sort(num,num+n);
    if(k%2!=0)
       sum=sum-num[0]*2;
    printf("%lld",sum);
    return 0;
}
