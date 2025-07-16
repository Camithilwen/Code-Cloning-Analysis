// lcmとか__builtin_popcountとかはg++ -std=c++17 default.cppみたいなかんじで
// -fsanitize=undefinedでオーバーフロー検出,オーバーフローする入力を投げるとよい
#include <bits/stdc++.h>
#define mod 1000000007
#define INF LLONG_MAX
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define NO cout<<"NO"<<endl
#define YES cout<<"YES"<<endl
#define No cout<<"No"<<endl
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
using namespace std;
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};
bool comp(pair<ll, ll> a, pair<ll , ll> b) {
    // 基本はfirstで比較
    if(a.first != b.first){
        // return a.first < b.first; // 昇順
        return a.first > b.first; // 降順
    }

    // それ以外はsecondで比較
    if(a.second != b.second){
        return a.second > b.second;
    }else{
        // どちらも同じ
        return true;
    }
}


int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
 
    ll a,b,d,m,n,maxi=0,f=0,mini=INF,sum=0;
    string str,stra="CODEFESTIVAL2016";
    ll k;
    ll w,x,y;
    ll h;
    cin>>n;
    vector<ll> v(n);
    rep(i,n) cin>>v[i];
    map<ll,ll> m1;
    map<ll,ll> m2;
    set<ll> s1;
    set<ll> s2;
    rep(i,n){
        if(i%2) {
            s1.insert(v[i]);
            m1[v[i]]++;
        }else{
            s2.insert(v[i]);
            m2[v[i]]++;
        }
    }
    vector<pair<ll,ll>> p1(s1.size()+1);
    vector<pair<ll,ll>> p2(s2.size()+1);
    p1[s1.size()]=make_pair(0,-1);
    p2[s2.size()]=make_pair(0,-2);
    ll i=0;
    for(auto itr=s1.begin();itr!=s1.end();itr++,i++){
        p1[i]=make_pair(m1[*itr],*itr);
    }
    i=0;
    for(auto itr=s2.begin();itr!=s2.end();itr++,i++){
        p2[i]=make_pair(m2[*itr],*itr);
    }
    sort(all(p1),comp);
    sort(all(p2),comp);
    if(p1[0].second==p2[0].second){
        cout<<n-max(p1[1].first+p2[0].first,p1[0].first+p2[1].first)<<endl;
    }else{
        cout<<n-(p1[0].first+p2[0].first)<<endl;
    }


    
    return 0;
}
