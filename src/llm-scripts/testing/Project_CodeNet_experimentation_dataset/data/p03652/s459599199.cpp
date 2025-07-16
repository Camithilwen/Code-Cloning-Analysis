#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define F first
#define S second
#define int long long

const int maxn = 310;
const ll inf = 1e18+10;
//const int mod = 998244353;
//const int mod = 1e9+7;

int n, m;
int a[maxn][maxn], ptr[maxn], cnt[maxn];
bool mark[maxn];

bool ok(int q)
{
   // cout<< q <<" ";
    set<pair<int,int>> se;
    for(int i = 1; i <= m; i++) cnt[i] = 0;
    for(int i = 1; i <= n; i++)
    {
        ptr[i] = 1;
        cnt[a[i][ptr[i]]]++;
    }
    for(int i = 1; i <= m; i++)
    {
        se.insert({cnt[i],i});
        mark[i] = 0;
    }

    while(se.size())
    {
        // cout<< se.size() <<" ";
        auto it = se.end(); it--;
        int X = (*it).S;
        //cout<< X <<" "<< cnt[X] <<" \n";
        if(cnt[X] <= q) return 1;

        se.erase(it);
        if(se.empty()) return 0;

        mark[X] = 1;
        for(int i = 1; i <= n; i++)
        {
            if(mark[a[i][ptr[i]]] == 0) continue;
            while(mark[a[i][ptr[i]]])
                ptr[i]++;
          //  if(X == 2)
          //      cout<< i <<" "<< ptr[i] <<"\n";
            int Y = a[i][ptr[i]];
            se.erase({cnt[Y],Y});
            cnt[Y]++;

          //  if(X == 2)
         //       cout<< Y <<" "<< cnt[Y] <<"\n";

            se.insert({cnt[Y],Y});
        }
    }
    return 0;
}

signed main()
{
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin>> a[i][j];

    int hi = n+1, lo = 0;
    while(hi-lo > 1)
    {
        int tm = (hi+lo) >> 1;
        if(ok(tm)) hi = tm;
        else lo = tm;
    }
    //cout<< ok(2) <<" ";
    cout<< hi;
}


