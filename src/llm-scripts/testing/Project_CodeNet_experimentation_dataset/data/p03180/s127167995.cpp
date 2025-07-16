/*------------------RandomStuff------------------*/
//      Author: CNH_Tourist
//      Date: 30/08/2020
//      Time: 15:26:22
/*-----------------------------------------------*/
#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unrolled-loops")
using namespace std;
/*---------------------Define--------------------*/
#define filename "TestCode"
#define pi acos(-1)
#define endl '\n'
#define X first
#define Y second
#define pb push_back
#define pf push_front
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ll long long
#define ull unsigned long long
#define hash OoOoO
#define gcd __gcd
#define y1 FlyingTuna 
/*-----------------------------------------------*/
const long long mod  = 1e9+7;
const long long mod2 = 1e9+9;
const long long INF  = 1e15;
const long long oo   = 2e18+7;
const long long base = 31;
const double eps = 1e-8;
int test=1;
/*-----------------------------------------------*/
void FlyingTuna()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
/*
    ifstream *fi = new ifstream (filename".inp");
    ofstream *fo = new ofstream (filename".out");
    if(*fi)
    {
        cin.rdbuf( fi->rdbuf() );
        cout.rdbuf( fo->rdbuf() );
    }
*/
}
/*-------------------Global----------------------*/
int n;
ll d[100010];
ll f[100010], a[17][17];
/*------------------Functions--------------------*/

/*-----------------------------------------------*/
void In()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            cin >> a[i][j];
}

void Solve()
{
    In();

    for(int mask = 1; mask < 1 << n; mask ++)
    {
        for(int i = 0; i < n; i ++)
            for(int j = i + 1; j < n; j++)
                if((1 & (mask >> i)) == 1 && (1 & (mask >> j)) == 1)
                    d[mask] += a[i+1][j+1];
    }

    for(int mask = 1; mask < 1 << n; mask ++)
    {
        f[mask] = max(f[mask], d[mask]);
        for(int i = mask; i > 0; i =((i-1)&mask))
            f[mask] = max(f[mask], f[i] + d[i^mask]);
    }
    
    int t = (1 << n) - 1;
    cout << f[t];

}

int32_t main()
{
    FlyingTuna();
    
    //cin>>test;while(test--)
    Solve();

}