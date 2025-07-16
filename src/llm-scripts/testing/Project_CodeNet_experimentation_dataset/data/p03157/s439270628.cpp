//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int find_(int x,vector<pair<ll,ll>> &v){
    if(v[x].first<0) return x;
    v[x].first=find_(v[x].first,v);
    return v[x].first;
}

int same_(int a,int b,vector<pair<ll,ll>> &v){
    if(find_(a,v)==find_(b,v)) return 1;
    return 0;
}

void union_(int a,int b,vector<pair<ll,ll>> &v){
    if(same_(a,b,v)) return;
    int a_p=find_(a,v),b_p=find_(b,v);
    if(a_p>b_p) swap(a_p,b_p);
    v[a_p].first+=v[b_p].first; 
    v[a_p].second+=v[b_p].second;
    v[b_p].first=a_p;
}

/*
void print_v(vector<pp> v){
    rep(i,v.size()) cout<<v[i]<<" ";
    cout<<endl;
}

int size_(int a,vector<pp> &v){
    return -v[find_(a,v)];
}
*/

int main() {
    int h,w; cin>>h>>w;
    vector<string> s(h,"");
    rep(i,h) cin>>s[i];
    vector<pair<ll,ll>> v(h*w,mk(-1,0));
    rep(i,h*w){
        if(s[i/w][i%w]=='#') v[i].second=-1;
    }
    rep(i,(h-1)*w) if(s[i/w][i%w]!=s[i/w+1][i%w]) union_(i,i+w,v);
    rep(i,h*w){
        if(i%w==w-1) continue;
        if(s[i/w][i%w]!=s[i/w][i%w+1]) union_(i,i+1,v);
    }
    ll ans=0;
    rep(i,h*w){
        if(v[i].first<0)
        ans+=(-v[i].second)*(v[i].second-v[i].first);
    }
    cout<<ans<<endl;
}