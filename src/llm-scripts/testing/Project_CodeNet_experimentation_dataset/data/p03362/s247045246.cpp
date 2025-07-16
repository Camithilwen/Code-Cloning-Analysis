#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>
#define LL long long
#define N 55555
#define maxn 10005
#define INF 0x3f3f3f3f
#define mase(a,b) memset(a,b,sizeof(a))
#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)
#define DS DisputeSegement
using namespace std;
bool isPrime(int fig)
{
    int limit=(int)sqrt(fig)+1;
    for(int i=2;i<limit;i++)
    {
        if(fig%i==0)
        {
            return false;
        }

    }
    return true;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=11;i<=N;i+=10)
    {
        if(isPrime(i))
        {
            printf("%d",i);
            n--;
            printf("%c",n?' ':'\n');
            if(!n)
            {
                break;
            }
        }
    }
    return 0;
}


//Five,Five Everywhere,原创者CSDN@
