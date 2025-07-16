#include<bits/stdc++.h>
using namespace std;

int n,q;
int c[500005],pre[500005],ans[500005];
vector<pair<int,int>> qs[500005];
int bit[2000005];

int sum(int pos){
    int res=0;
    while(pos>0){
        res+=bit[pos];
        pos-=pos&-pos;
    }
    return res;
}

void add(int pos,int val){
    while(pos<=n){
        bit[pos]+=val;
        pos+=pos&-pos;
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=q;i++){
        int l,r;
        cin>>l>>r;
        qs[r].emplace_back(l,i);
    }
    for(int i=1;i<=n;i++){
        add(i,1);
        if(pre[c[i]])add(pre[c[i]],-1);
        pre[c[i]]=i;
        for(pair<int,int> &p:qs[i]){
            ans[p.second]=sum(i)-sum(p.first-1);
        }
    }
    for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';

    return 0;
}