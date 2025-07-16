#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll Mod = 1000000007;
bool exists(vector<ll>& vec,ll x)
{
    auto pos = lower_bound(vec.begin(),vec.end(),x);
    if(pos == vec.end())return false;
    return *pos == x;
}
void solve(ll N, ll M, vector<ll> A, vector<ll> B)
{
    ll ans = 1;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    ll empty = 0;
    ll numrow=0,numcol=0;
    for(ll x = M*N;x>=1;--x)
    {
        if(exists(A,x))
        {
            if(exists(B,x))
            {
                empty += numcol + numrow;
                numcol++;
                numrow++;
            }else
            {
                empty += numcol - 1;
                ans *= numcol;
                ans %= Mod;
                numrow++;
            }
        }else
        {
            if(exists(B,x))
            {
                empty += numrow - 1;
                ans *= numrow;
                ans %= Mod;
                numcol++;
            }else
            {
                if(empty <= 0)
                {
                    cout<<0<<endl;
                    return;
                }
                ans *= empty;
                empty--;
                ans %= Mod;
            }
        }
    }
    cout<<ans<<endl;
}


int main()
{
    ll N;
    cin >> N;
    ll M;
    cin >> M;
    vector<ll> A(N);
    for(int i = 0 ; i < N ; i++)
    {
        cin >> A[i];
    }
    vector<ll> B(M);
    for(int i = 0 ; i < M ; i++)
    {
        cin >> B[i];
    }
    solve(N, M, move(A), move(B));
    return 0;
}
