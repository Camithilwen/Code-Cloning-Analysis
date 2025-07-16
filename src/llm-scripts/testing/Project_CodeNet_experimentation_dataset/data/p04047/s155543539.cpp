#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ii pair<int,int>
#define iii pair <int,ii>
#define iil pair<ll,ll>
#define iiil pair<ll,iil>
#define max3(a,b,c) max(a, max(b,c))
#define min3(a,b,c) min(a, min(b,c))
#define s(v) sort(v.begin(),v.end())
#define pf printf
#define sf scanf
#define MIN INT_MIN
#define MAX INT_MAX
#define Accepted 0
#define GCD(x,y)  __gcd(x, y)
#define endl "\n"
using namespace std;
/**
const int maxn = 1e5 * 3;
int vis[maxn],l[maxn];
int indegree[maxn];
vector<int> graph[maxn];
vector<int> order;
vector<int> cst[maxn];

int gx[]= {2,2,-2,-2,1,-1,1,-1};
int gy[] ={1,-1,1,-1,2,2,-2,-2};

void DFS(int a,bool tpsort){
        vis[a] = 1;
    for(int i=0;i<graph[a].size();i++){
        int r = graph[a][i];
            if(vis[r]==0){
                DFS(r,tpsort);
            }
    }
    if(tpsort)order.push_back(a);
}

int vis[maxn],l2[maxn];

void BFS(int root){
    memset(vis,0,sizeof(vis));
    memset(l,0,sizeof(l));
    vis[root] = 1;
    l[root] = 0;
    queue <int> q;
    ans = 0;
    mx = root;
    q.push(root);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        int p = graph[cur].size();
        for(int i=0;i<p;i++){
            int r = graph[cur][i];
            if(vis[r]==0){
                vis[r] = 1 ;
                l[r] = l[cur] + cst[cur][i];
                if(l[r]>ans){
                    ans = l[r];
                    mx = r;
                }
                q.push(r);
            }
        }
    }
   // cout<< ans <<endl;
}

**/

int main(){
    //fast
    int n,val;  cin >> n;
    vector<int> v;

    for(int i=0;i<2*n;i++){
        cin>>val;
        v.pb(val);
    }

    s(v);
    int sum = 0;
    for(int i=0;i<2*n;i+=2){
        sum+=v[i];
    }
        cout << sum << endl;



    return Accepted;
}
