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

int digit[50];
void solve(){
    int n;
    cin >> n;
    if(n==0){
        print(0);
        return;
    }
    bool plus=true;
    if(n<0) {
        plus=false;
        n=-n;
    }
    int ctr=0;
    while(n>0){
        if(n&1){
            digit[ctr]=1;
        }
        ctr++;
        n/=2;
    }
    if(plus){
        for(ll i=ctr-1; i>0; i--){
            if(i&1){
                if(digit[i]==1) digit[i+1]++;
            }
        }
        repi(i,1,45){
            while(digit[i]>1){
                digit[i+1]++;
                digit[i+2]++;
                digit[i]-=2;
            }
        }
    }
    else{
        for(ll i=ctr-1; i>=0; i--){
            if(i%2==0){
                if(digit[i]==1) digit[i+1]++;
            }
        }
        repi(i,1,45){
            while(digit[i]>1){
                digit[i+1]++;
                digit[i+2]++;
                digit[i]-=2;
            }
        }
    }
    bool start=false;
    for(ll i=38;i>=0;i--){
        if(!start&&digit[i]==0) continue;
        if(!start&&digit[i]==1){
            start=true;
            cout << digit[i];
            continue;
        }
        cout << digit[i];
    }
    cout << endl;
    return;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    solve();
    return 0;
}