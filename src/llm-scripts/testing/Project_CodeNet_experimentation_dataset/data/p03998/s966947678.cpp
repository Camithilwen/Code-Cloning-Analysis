#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair< ll, ll > Pi;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
const ll INF = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
#define all(x) x.begin(), x.end()
#define mp make_pair
bool compare(Pi a, Pi b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}


bool In_map(ll y,ll x,ll h,ll w){
    if(y<0 || x<0 || y>=h || x>=w){
        return 0;
    }else{
        return 1;
    }
}
const vector<ll> dx{1,0,-1,0};
const vector<ll> dy{0,1,0,-1};


int main() {
    vector<queue<ll>>que(3);

    vector<string>S(3);
    rep(i,3){
        char c;
        cin>>S[i];
        rep(j,S[i].size()){
            que[i].push(S[i][j]-'a');
        }
       // cout<<que[i].size()<<endl;
    }
    

    ll now=que[0].front();
    que[0].pop();
    while(1){
        //cout<<now<<" "<<que[now].size()<<endl;
        if(que[now].empty()){
            cout<<(char)(now+'A')<<endl;
            return 0;
        }else{
            //cout<<now<<endl;
            ll tmp;
            tmp=que[now].front();
            que[now].pop();
            now=tmp;
            
            
        }
    }
    


    return 0;
    

}