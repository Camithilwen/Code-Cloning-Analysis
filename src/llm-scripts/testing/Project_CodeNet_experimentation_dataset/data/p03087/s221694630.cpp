#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const double PI=acos(-1.0);

int N,Q; string S; vi l,r;
void input()
{
    cin>>N>>Q;
    cin>>S;
    for(int i=0;i<Q;++i){
        int a,b; cin>>a>>b; 
        l.emplace_back(a); r.emplace_back(b);
    }
}

void solve()
{
    vi rui(N+1,0);
    for(int i=2;i<N+1;++i){
        rui[i]=rui[i-1];
        if(S[i-2]=='A' && S[i-1]=='C') ++rui[i];
    }
    for(int i=0;i<Q;++i){
        int ans=rui[r[i]]-rui[l[i]-1];
        if(l[i]>1 && S[l[i]-2]=='A' && S[l[i]-1]=='C') --ans;
        cout<<ans<<endl;
    }
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}