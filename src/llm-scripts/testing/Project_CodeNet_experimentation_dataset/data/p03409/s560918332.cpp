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
#define _GLIBCXX_DEBUG
int main(){
    int n;
    cin>>n;
    vpii red(n),blue(n);
    rep(i,n){
        int a,b;
        cin>>a>>b;
        red[i]=mp(a,b);
    }
    rep(i,n){
        int c,d;
        cin>>c>>d;
        blue[i]=mp(d,c);
    }
    sort(all(red));
    reverse(all(red));
    sort(all(blue));
    rep(i,n){
        int c,d;
        tie(d,c)=blue[i];
        blue[i]=mp(c,d);
    }
    vbo tmp(n,true);
    int ans=0;
    rep(i,n){
        rep(j,n){
            if(red[i].first<blue[j].first&&red[i].second<blue[j].second&&tmp[j]){
                ans++;
                tmp[j]=false;
                break;
            }
        }
    }
    cout<<ans<<endl;
}