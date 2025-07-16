#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const ll inf=1e9+7;
const ll INF=1e18;

int main(){
    int n,q;cin>>n>>q;
    int S,T,X;
    vector<tuple<int,int,int>> ban(n);
    rep(i,n){
        cin>>S>>T>>X;
        ban[i]=make_tuple(X,S-X,T-X);
    }
    sort(all(ban));
    int d;
    map<int,int> num;
    set<int> time;
    rep(i,q){
        cin>>d;
        num[d]=i;
        time.insert(d);
    }
    time.insert(inf);
    vin ans(q,-1);
    //s<=d<tなるdをxが小さい順に見つけていく
    queue<int> que;
    int x,s,t;
    rep(i,n){
        if(time.size()==1)break;
        x=get<0>(ban[i]);
        s=get<1>(ban[i]);
        t=get<2>(ban[i]);
        auto l=time.lower_bound(s);
        auto r=time.lower_bound(t);
        for(auto itr=l;itr!=r;itr++){
            ans[num[*itr]]=x;
            que.push(*itr);
        }
        while(que.size()){
            time.erase(que.front());
            que.pop();
        }
    }
    rep(i,q)cout<<ans[i]<<endl;
}