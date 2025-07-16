#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false)
int a[200000], vs[200000],vs1[100006],p[300000];
vector<int>v[200000];
queue<int>q;
int f(int n)
{
    int i, k=0;
    vs[n]=1; q.push(n);
    while(q.size()){
            n=q.front(); q.pop();
    for(i=0; i<v[n].size(); i++){
        if(vs1[v[n][i]]==1){
        p[v[n][i]]=n;
        q.push(v[n][i]);
    }
    else vs1[v[n][i]]--;
    }
    }
    return 1;
}
int main()
{
    IO;
    int i, j, m, k, n, t, l=0, mx,ll,mxx,mx1;
    cin>>n>>m;
    for(i=1; i<=n+m-1; i++){
        cin>>j>>k;
        v[j].push_back(k);
        vs1[k]++;
    }
    for(i=1; i<=n; i++)
        if(vs1[i]==0)k=i;
    f(k);
    for(i=1; i<=n; i++) cout<<p[i]<<endl;
    return 0;

}
