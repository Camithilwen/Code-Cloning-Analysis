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
    int n;cin>>n;
    vector<queue<int>> tennis(n);
    int a;
    rep(i,n)rep(j,n-1){
        cin>>a;
        tennis[i].push(a-1);
    }
    vector<queue<int>> match(2);
    rep(i,n)match[0].push(i);
    int ans=0,cnt=0,tmp,res=0;;bool can;
    while(1){
        ans++;
        vbo already(n,false);
        can=false;
        while(match[res].size()){
            int i=match[res].front();match[res].pop();
            if(tennis[i].size()==0)continue;
            if(!already[i]){
                tmp=tennis[i].front();
                if(i==tennis[tmp].front()&&!already[tmp]){
                    cnt++;
                    tennis[i].pop(); tennis[tmp].pop();
                    match[(res+1)%2].push(i);match[(res+1)%2].push(tmp);
                    already[i]=true;already[tmp]=true;
                    can=true;
                }
            }
        }
        if(cnt==n*(n-1)/2){
            cout<<ans<<endl;
            return 0;
        }
        if(!can){
            cout<<-1<<endl;
            return 0;
        }
        res=(res+1)%2;
    }
}