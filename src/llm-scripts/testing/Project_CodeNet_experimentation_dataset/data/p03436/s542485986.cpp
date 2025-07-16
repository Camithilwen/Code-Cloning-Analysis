#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////////
const long long int INF = 1LL<<60;
const long long int Mod = 1000000007;
using ll = long long int; using ci = const int;
using vi = vector<int>;  using Vi = vector<long long int>;
using P = pair<int, int>;  using PLL = pair<ll, ll>;
using matrix = vector<vector<ll>>;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define rp(i,N) for(ll i = 0; i < (ll)N; i++)
#define repi(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
template<class T>bool chmax(T &former, const T &b) { if (former<b) { former=b; return true; } return false; }
template<class T>bool chmin(T &former, const T &b) { if (b<former) { former=b; return true; } return false; }
template<class T>T sqar(T x){ return x*x; }//sqrt(x)は平方根;
#define Sort(v) std::sort(v.begin(), v.end(), std::greater<decltype(v[0])>()) //降順でVをソート
#define p_queue(v) priority_queue<v, vector<v>, greater<v> >
template<class T> inline void princ(T x){cout<<x<<" ";}; 
template<class T> inline void print(T x){cout<<x<<"\n";};
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
///////////////////////////////////////////////////////////////////////////////////


void solve(){
    matrix dxdy={{1,0},{-1,0},{0,1},{0,-1}};
    ll h,w;
    cin >> h >> w;
    vector<vector<char>> s(h,vector<char>(w));
    ll ctr=0;
    rp(i,h){
        rp(j,w){
            cin >> s[i][j];
            if(s[i][j]=='#') ctr++;
        }
    }
    queue<pair<P,ll>> que;
    que.push(mp(mp(0,0),0));
    matrix seen(h,Vi(w,0));
    ll shortest=-1;
    while(!que.empty()){
        P loc=que.front().first;
        ll dist=que.front().second;
        que.pop();
        if(seen[loc.first][loc.second]==1) continue;
        if(loc.first==h-1&&loc.second==w-1) {
            shortest=dist;
            break;
        }
        seen[loc.first][loc.second]=1;
        for(auto vec:dxdy){
            if(loc.first+vec[0]<0||loc.first+vec[0]>=h||loc.second+vec[1]<0||loc.second+vec[1]>=w) continue;
            if(s[loc.first+vec[0]][loc.second+vec[1]]=='.'){
                que.push(mp(mp(loc.first+vec[0],loc.second+vec[1]),dist+1));
            }
        }
    }
    if(shortest==-1){
        print(-1);
    }else{
        print(h*w-ctr-shortest-1);
    }

    return;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    solve();
    return 0;
}