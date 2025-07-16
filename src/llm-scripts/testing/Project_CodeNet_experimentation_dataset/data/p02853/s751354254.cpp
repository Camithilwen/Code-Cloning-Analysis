#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int main()
{
    int x[2],ans=0;
    for (int i = 0; i < 2; i++)
    {
        cin>>x[i];
        if(x[i]==1) ans+=300000;
        if(x[i]==2) ans+=200000;
        if(x[i]==3) ans+=100000;
    }
    if(x[0]==1&&x[1]==1) ans+=400000;
    cout<<ans<<endl;

    return 0;
}