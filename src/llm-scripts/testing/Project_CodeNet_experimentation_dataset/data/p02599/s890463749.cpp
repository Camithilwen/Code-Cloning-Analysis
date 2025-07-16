// by ynymxiaolongbao 
#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define N 500010

//FenwickTree↓
int dat[N];
void init(){
    rep(i,N)dat[i]=0;
}
void add(int i,int x){
    for(;i<N;i+=i&-i)dat[i]+=x;
}
int sum(int i){
    int res=0;
    for(;i>0;i-=i&-i)res+=dat[i];
    return res;
}
int rangesum(int l,int r){//[l,r]
    return sum(r)-sum(l-1);
}
//FenwickTree↑

int a[N];
vector<int> ql[N],qid[N];
int ans[N];

int n,q,c[N];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>c[i];
    rep(i,q){
        int l,r;
        cin>>l>>r;
        ql[r].push_back(l);
        qid[r].push_back(i);
    }
    init();
    for(int i=1;i<=n;i++)a[i]=0;
    for(int i=1;i<=n;i++){
        if(a[c[i]]>0)add(a[c[i]],-1);
        add(i,+1);
        a[c[i]]=i;
        rep(j,ql[i].size()){
            ans[qid[i][j]]=rangesum(ql[i][j],i);
        }
    }
    rep(i,q)cout<<ans[i]<<"\n";
}
