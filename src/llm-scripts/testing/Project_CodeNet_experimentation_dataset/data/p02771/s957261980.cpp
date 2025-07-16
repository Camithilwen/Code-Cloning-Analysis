#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=2e5+5,M=1e9+7;
const int LINF = 0x3f3f3f3f3f3f3f3f;
//did u check when n=1?
//is mxN correct?
set<int>s;
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<3;i++){
        int x;cin>>x;
        s.insert(x);
    }
    if(sz(s)!=2)cout<<"No";
    else cout<<"Yes";
}