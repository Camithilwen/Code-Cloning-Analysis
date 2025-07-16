#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;
const int N = 2e5+5;


vector<ll>ans,veca,vecb;
vector<int>adj[N];
vector<double>aka;
vector<pair<int,double>>dp[N];
vector<bool>vis;


void init(int n){
    ans.clear();veca.clear();aka.clear();vis.clear();ans.resize(n);
    vecb.clear(),vecb.resize(n);veca.resize(n);vis.resize(n);
    for (int i = 0; i <n; i++) {
        vis[i]=0;
    }
    for (int i = 0; i<=n; i++) {
        adj[i].clear();
    }
    for (int i = 0; i <=n; i++) {
        dp[i].clear();
    }
    for (int i = 0; i < n; i++) {
        ans[i]=0;
    }
}

int check(int a,int b,int c){
    int res=0;
    if(a+b>c) res=1;
    return res;
    
}
bool valid(int a,int b,int c){
    if((a<b)&&(b<c)) return 0;
    return 1;
}
void solve(){
    int n,flag=0;
    cin>>n;
    init(n);
    for (int i = 0; i <n; i++) {
        cin>>veca[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if(!valid(i,j,k)){
                    set<int>st;vector<int>vec;
                    st.insert(veca[i]);st.insert(veca[j]);st.insert(veca[k]);
                    vec.push_back(veca[i]);vec.push_back(veca[j]);vec.push_back(veca[k]);
                    if(st.size()==3){
                        sort(vec.begin(),vec.end());
                        flag+=check(vec[0],vec[1],vec[2]);
                    }
                }
            }
        }
    }
    cout<<flag<<"\n";
    
}

int main(){
   
   
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
        
        
    return 0;
}