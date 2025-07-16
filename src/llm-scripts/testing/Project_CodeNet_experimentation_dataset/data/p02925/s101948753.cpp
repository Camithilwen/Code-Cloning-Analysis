#include<bits/stdc++.h>
using namespace std;
const int inf=1000000000;
int N=1000000;
vector<int>d(N,-inf);
vector<int>check(N,0);
vector<vector<int>>e(N);
int dfs(int v){
    if(d[v]!=-inf)return d[v];
    if(e[v].size()==0)return d[v]=1;
    for(int i=0;i<e[v].size();i++){
        int u=e[v][i];
        if(check[u]==1 && d[u]==-inf)return d[v]=inf;//non-DAG
        check[u]=1;
        d[v]=max(d[v],dfs(u)+1);
    }
    return d[v];
}
int main(){
    int n;
    cin>>n;
    int a[n][n-1];
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            cin>>a[i][j];
            a[i][j]--;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-2;j++){
            e[min(i,a[i][j])*1000+max(i,a[i][j])].push_back
            (min(i,a[i][j+1])*1000+max(i,a[i][j+1]));
        }
    }
    int m=0;
    for(int i=0;i<N;i++)m=max(m,dfs(i));
    if(m>=inf)cout<<"-1"<<endl;
    else cout<<m<<endl;
    return 0;
}
