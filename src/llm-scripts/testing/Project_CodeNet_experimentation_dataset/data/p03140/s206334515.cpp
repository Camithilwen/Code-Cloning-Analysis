#define rep(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define rrep(i,a,b) for(ll i=(b)-1; i>=a; --i)
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define scanv(n,v) v.resize(n); rep(i,n){ cin>>v[i];}
#define MOD 1000000007ll
#define Yes(flag) cout<<((flag)? "Yes":"No");
#define YES(flag) cout<<((flag)? "YES":"NO");
#define be begin
#define pb push_back
#define fi first
#define se second
#define square(x) x*x
#include<bits/stdc++.h>
using ll = long long;
using namespace std;
template<class T>T 
chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T>T 
chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
//------------------------------------------------------
int eq(char a,char b,char c){
    vector<char> k{a,b,c};
    sort(ALL(k));
    return distance(k.begin(),unique(ALL(k)))-1;
}

int n;
string a,b,c;
void input(){
    cin>>n>>a>>b>>c;
}
void src(){
    int ans=0;
    rep(i,n){
        ans+=eq(a[i],b[i],c[i]);
    }
    cout<<ans;
}    
int main(int argc,char* argv[]){
    ios::sync_with_stdio(false);
   // ifstream in( argv[1] ); cin.rdbuf(in.rdbuf());
    input();
    src();    
}