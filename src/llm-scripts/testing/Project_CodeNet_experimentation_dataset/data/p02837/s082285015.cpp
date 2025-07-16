#include<bits/stdc++.h>
using namespace std;
#define lint long long
#define inf 1000000007
#define mod 1000000007
#define MAX 100005
#define pb push_back
#define mp make_pair
#define vit vector<int>::iterator
typedef pair<int,int> pii;
vector<pii> V[MAX];
int pos[MAX],flg,visited[MAX];
void dfs(int u){
    visited[u]=1;
    for(auto v:V[u]){
        if(v.second){
            if(!pos[v.first]){
                pos[v.first]=1;
                dfs(v.first);
            }
            else if(pos[v.first]==1){
                if(!visited[v.first])
                    dfs(v.first);
            }
            else flg=1;
        }
        else{
            if(!pos[v.first]) pos[v.first]=2;
            else if(pos[v.first]==1) flg=1;
        }
    }
}
int possible(int k,int n){
    vector<int>vec;
    for(int i=0;i<(n-k);i++) vec.pb(0);
    for(int i=0;i<k;i++) vec.pb(1);
    do{
        flg=0;
        for(int i=1;i<=n;i++){
            visited[i]=0;
            pos[i]=vec[i-1];
        }
        for(int i=1;i<=n;i++){
            if(!visited[i] && vec[i-1]){
                dfs(i);
            }
        }
        if(!flg)
            return 1;

    }while(next_permutation(vec.begin(),vec.end()));
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        for(int j=0;j<a;j++){
            int x,y;
            cin>>x>>y;
            V[i+1].pb(mp(x,y));
        }
    }
    int lo,hi,mid;
    lo=0;
    hi=n;
    while(hi>lo){
        mid=(lo+hi+1)/2;
        if(possible(mid,n)) lo=mid;
        else hi=mid-1;
    }
    cout<<lo;
}
