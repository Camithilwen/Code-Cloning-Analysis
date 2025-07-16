#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll>pll;

ll n,x[100010]={0},y[100010]={0};
vector<pll>vx,vy;
vector<pll>edge[100010];
priority_queue<pll,vector<pll>,greater<pll>>q;
//priority_queue<pll>q;
bool used[100010];
ll res=0;

signed main(){

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>x[i]>>y[i];
        vx.push_back(pll(x[i],i));
        vy.push_back(pll(y[i],i));
    }

    sort(vx.begin(),vx.end());
    sort(vy.begin(),vy.end());
    for(int i=0;i<n-1;++i){
        ll j=vx[i].second,k=vx[i+1].second;
        ll wj=vx[i].first,wk=vx[i+1].first;
        edge[j].push_back(pll(wk-wj,k));
        edge[k].push_back(pll(wk-wj,j));
        j=vy[i].second,k=vy[i+1].second;
        wj=vy[i].first,wk=vy[i+1].first;
        edge[j].push_back(pll(wk-wj,k));
        edge[k].push_back(pll(wk-wj,j));
    }

    for(int i=0;i<n;++i){
        used[i]=false;
    }
    int c=1;
    for(int i=0;i<edge[0].size();++i)q.push(edge[0][i]);
    used[0]=true;
    while(c<n){
        pll t=q.top();
        q.pop();
        if(!used[t.second]){
            res+=t.first;
            for(int i=0;i<edge[t.second].size();++i){
                q.push(edge[t.second][i]);
            }
            used[t.second]=true;
            c++;
            //cout<<t.first<<" "<<t.second<<endl;
        }
    }

    cout<<res<<endl;

    return 0;
}