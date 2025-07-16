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
    ll n;
    cin >> n;
    Vi a(n);
    rp(i,n){
        string s;
        cin >> s;
        int si=s.size();
        bool point=false;
        int num=0;
        rp(j,si){
            if(s[j]=='.') {
                point=true;
                num=si-j-1;
                continue;
            }
            if(point){
                s[j-1]=s[j];
            }
        }
        if(point) s[si-1]='0';
        ll aa=stoll(s);
        if(!point) aa*=1000000000;
        else{
            rp(j,9-num-1)aa*=10;
            if(num==9) aa/=10;
        }
        a[i]=aa;
    }
    matrix mat(19,Vi(19,0)),summat(19,Vi(19,0));
    rp(i,n){
        ll t=0,f=0;
        ll as=a[i];
        while(as%2==0){
            as/=2;
            t++;
        }
        while(as%5==0){
            as/=5;
            f++;
        }
        if(t>18)t=18;
        if(f>18)f=18;
        mat[t][f]++;
    }
    for(ll i=18; i>=0; i--){
        for(ll j=18; j>=0; j--){
            if(i==18&&j==18){
                summat[i][j]=mat[i][j];
                continue;
            }
            if(i==18){
                summat[i][j]=summat[i][j+1]+mat[i][j];
                continue;
            }
            if(j==18){
                summat[i][j]=summat[i+1][j]+mat[i][j];
                continue;
            }
            summat[i][j]=summat[i+1][j]+summat[i][j+1]-summat[i+1][j+1]+mat[i][j];
        }
    }
    ll ans=0;
    rp(i,19){
        rp(j,19){
            if(i>=9&&j>=9){
                ans+=mat[i][j]*(summat[18-i][18-j]-1);
                continue;
            }
            ans+=mat[i][j]*summat[18-i][18-j];
        }
    }
    ans/=2;
    print(ans);
    return;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    solve();
    return 0;
}