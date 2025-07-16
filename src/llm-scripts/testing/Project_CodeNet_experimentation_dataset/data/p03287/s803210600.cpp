#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;
int n,m;
ll x,sum,ans;
map<ll,int>mmp;
int main()
{
    scanf("%d%d",&n,&m);
    sum=0;
    ans=0;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&x);
        sum+=x;
        ans+=mmp[sum%m];
        if(sum%m==0) ans++;
        mmp[sum%m]++;
    }
    printf("%lld\n",ans);
    return 0;
}