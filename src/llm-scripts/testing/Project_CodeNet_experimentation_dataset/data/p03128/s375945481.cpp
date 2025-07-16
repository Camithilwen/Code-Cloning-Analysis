#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////////
const long long int INF = INT64_MAX;
const long long int Mod = 1000000007;
using ll = long long int; using ci = const int;
using vi = vector<int>;
using Vi = vector<long long int>;
typedef pair<int, int> P; typedef pair<ll, ll> PLL;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define rep(i,N) for(ll i=0;i<N;i++)
auto max(auto x,auto y){if(x>y){return x;}else{return y;}}
auto min(auto x,auto y){if(x>y){return y;}else{return x;}}
template<class T>bool chmax(T &former, const T &b) { if (former<b) { former=b; return true; } return false; }
template<class T>bool chmin(T &former, const T &b) { if (b<former) { former=b; return true; } return false; }
template<class T>T sqar(T x){ return x*x; }//sqrt(x)は平方根;
#define Sort(v) std::sort(v.begin(), v.end(), std::greater<decltype(v[0])>()) //降順でVをソート
typedef vector<vector<ll> > matrix;
void princ(auto x){cout<<x<<" ";}; void print(auto x){cout<<x<<"\n";};
///////////////////////////////////////////////////////////////////////////////////

ll n,m;
Vi a;
int mj[9];
vector<string> dp;
string calc(ll nu){
    if(!dp[nu].empty())return dp[nu];
    string ans,tmp;
    if(nu==0){
        ans.clear();
        return ans;
    }
    rep(i,9){
        if(mj[i]!=0){
            if(nu-i>=0){
                if(calc(nu-i).empty() && (nu-i)!=0)continue;
                tmp.assign(calc(nu-i));
                tmp += to_string(mj[i]);
                //cout<<"tmp"<<tmp<<endl;;
                if(ans.size()<tmp.size())ans = tmp;
                if(ans.size()== tmp.size() && ans < tmp)ans = tmp;
                tmp.clear();
            }
        }
    }
    dp[nu]=ans;
    return ans;
}

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    cin>>n>>m; a.resize(m);
    dp.resize(n+2);
    rep(i,m)cin>>a[i];
    sort(all(a));
    rep(i,9)mj[i]=0;
    rep(i,m){
        switch (a[i]){
            case 1: mj[2]=1;
                break;
            case 2: mj[5]=2;
                break;
            case 3: mj[5]=3;
                break;
            case 4: mj[4]=4;
                break;
            case 5: mj[5]=5;
                break;
            case 6: mj[6]=6;
                break;
            case 7: mj[3]=7;
                break;
            case 8: mj[7]=8;
                break;
            case 9: mj[6]=9;
                break;
        }
    }
    print(calc(n));
    return 0;
}