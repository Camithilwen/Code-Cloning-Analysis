
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<time.h>
#include<vector>
using namespace std;
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int n,x,t;
    int ans;
    scanf("%d%d%d",&n,&x,&t);
    if(n%x==0)
        ans = n/x*t;
    else
        ans = n/x*t + t;
    printf("%d\n",ans);
    return 0;
}
