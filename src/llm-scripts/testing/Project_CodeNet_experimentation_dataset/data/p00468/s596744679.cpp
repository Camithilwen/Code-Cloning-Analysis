#include "bits/stdc++.h"

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

#define dump(x)  cerr << #x << " = " << (x) << endl
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb push_back

int main(){
    int n,m;
    int cost[600][600];
    while(cin>>n>>m){
        if(n==0&&m==0)break;
        rep(i,600)rep(j,600)cost[i][j]=999999999;
        rep(i,m){
            int a,b;
            cin>>a>>b;
            a--,b--;
            cost[a][b] = cost[b][a] = 1;
        }
        rep(k,n){
            rep(i,n){
                rep(j,n){
                    cost[i][j] = min(cost[i][j],cost[i][k]+cost[k][j]);
                }
            }
        }
        int sum=0;
        rep(i,600){
            if(cost[0][i]<=2&&i!=0)sum++;
        }
        cout<<sum<<endl;
    }
}