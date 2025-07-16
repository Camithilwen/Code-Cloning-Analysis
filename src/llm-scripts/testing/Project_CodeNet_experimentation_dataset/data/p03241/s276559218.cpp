#include <bits/stdc++.h>
 
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
#define FILL0(x) memset(x,0,sizeof(x))
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> P;
 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 

bool cmp(P a, P b)
{
    return a.first < b.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
 
 
    int N; 
    ll M;
 
    cin >> N >> M;

    if(N==1)
    {
        cout  << M << endl;
        return 0;
    }
 
    ll ans=0;
    vector<P> div;
    
    for(ll i=2; i*i<=M; i++)
    {
        ll cnt = 0; 
        if(M%i==0)
        {
            cnt=M/i;
            div.push_back(P(i, cnt));
            div.push_back(P(cnt, i));
        }
    }
 
    sort(div.begin(), div.end(), cmp);
    reverse(div.begin(), div.end());
 
    rep(i, div.size())
    {
        if(div[i].second>=N)
        {
            cout << div[i].first << endl;
            return 0;
        }
    }
 
    cout << 1 << endl;
    
 
 
 
 
 
    return 0;
 
 
}