#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
 
typedef vector<int> vi;;
typedef vector<ll> vll;

#define l() length()
#define sz() size()
 
#define b() begin()
#define e() end()
#define all(x) x.begin(), x.end()
 
#define pb(i) push_back(i)
#define PB() pop_back()
 
 
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define Fi first
#define Se second
 
const int maxx=1e6+9;
 
// Happy Coding!

ll _find(int d,int n){
    return n<100 ? pow(100,d)*n : 101*pow(100,d);
}

void solve(){
    
    
    int n;
    cin>>n;
    map<string,int> f;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        f[s]++;
    }
    
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        string s;cin>>s;
        f[s]--;
    }
    int ans=0;
    for(auto P:f){
        ans=max(ans,P.Se);
    }
    cout<<ans<<endl;
}

int main() {
    faster;
    int t=1;
    // cin>>t;
    while(t-->0){
        solve();
    }
	return 0;
}