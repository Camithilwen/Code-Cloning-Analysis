#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair< ll, ll > Pi;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
#define INF 200000000000
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
#define all(x) x.begin(), x.end()
#define mp make_pair
bool compare(pair<int, int> a, pair<int, int> b) {
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
    ll H,W;
    cin>>H>>W;
    vector<vector<char>> G(H,vector<char>(W));
    ll cnt = 0;
    rep(i,H){
        rep(j,W){
            cin>>G[i][j];
            if(G[i][j] == '.'){
                cnt++;
            }
        }
    }

    vector<vector<ll>> dist(H,vector<ll>(W,-1));
    queue<Pi> que;

    dist[0][0] = 0;
    que.push(mp(0,0));
    ll dis=-1;

    while(!que.empty()){
        Pi v =que.front();
        que.pop();
        if(v.first == H-1 && v.second == W-1){
            //flag =1;
            dis = dist[v.first][v.second];
            break;
        }
        rep(dir,4){
            ll ny = v.first + dy[dir];
            ll nx = v.second + dx[dir];

            if(!In_map(ny,nx,H,W)) continue;
            if(dist[ny][nx] != -1) continue;
            if(G[ny][nx] == '#') continue;
            dist[ny][nx] = dist[v.first][v.second]+1;
            que.push(mp(ny,nx));
        }

    }


    if(dis == -1){
        cout<<-1<<endl;
    }else{
        cout<<cnt-dis-1<<endl;
    }




    return 0;
    

}