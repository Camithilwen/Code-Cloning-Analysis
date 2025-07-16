#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(i,n) for (int i=0;i<(int)(n);i++)
#define codefor int test;scanf("%d",&test);while(test--)
#define yn(ans) if(ans)printf("Yes\n");else printf("No\n")
#define YN(ans) if(ans)printf("YES\n");else printf("NO\n")
#define vector2d(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))
#define umap unordered_map
#define uset unordered_set
using namespace std;
using ll = long long;
const int MOD=1000000007;
//入力系
void scan(int& a){scanf("%d",&a);}
void scan(long long& a){scanf("%lld",&a);}
template<class T> void scan(T& a){cin>>a;}
template<class T> void scan(vector<T>& vec){for(auto&& it:vec)scan(it);}
void in(){}
template <class Head, class... Tail> void in(Head& head, Tail&... tail){scan(head);in(tail...);}
//出力系
void print(const int& a){printf("%d",a);}
void print(const long long& a){printf("%lld",a);}
void print(const double& a){printf("%.15lf",a);}
template<class T> void print(const T& a){cout<<a;}
template<class T> void print(const vector<T>& vec){if(vec.empty())return;print(vec[0]);for(auto it=vec.begin();++it!= vec.end();){putchar(' ');print(*it);}}
void out(){putchar('\n');}
template<class T> void out(const T& t){print(t);putchar('\n');}
template <class Head, class... Tail> void out(const Head& head,const Tail&... tail){print(head);putchar(' ');out(tail...);}
//デバッグ系
template<class T> void dprint(const T& a){cerr<<a;}
template<class T> void dprint(const vector<T>& vec){if(vec.empty())return;cerr<<vec[0];for(auto it=vec.begin();++it!= vec.end();){cerr<<" "<<*it;}}
void debug(){cerr<<endl;}
template<class T> void debug(const T& t){dprint(t);cerr<<endl;}
template <class Head, class... Tail> void debug(const Head& head, const Tail&... tail){dprint(head);cerr<<" ";debug(tail...);}
ll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }

//素因数分解
template <typename T>
vector<pair<T, T>> prime_factor(T n) {
    vector<pair<T, T>> ret;
    T tmp=0;
    if(n%2==0){
        tmp=0;while(n%2==0){tmp++;n/=2;}
        ret.push_back(make_pair(2, tmp));
    }
    if(n%3==0){
        tmp=0;while(n%3==0){tmp++;n/=3;}
        ret.push_back(make_pair(3, tmp));
    }
    for (T i=5;i*i<=n;i+=4) {
        if(n%i==0){
            tmp=0;while(n%i==0){tmp++;n/=i;}
            ret.push_back(make_pair(i,tmp));
        }
        i+=2;
        if(n%i==0){
            tmp=0;while(n%i==0){tmp++;n/=i;}
            ret.push_back(make_pair(i,tmp));
        }
    }
    if(n!=1)ret.push_back(make_pair(n,1));
    return ret;
}

int main(){
    ll a,b;
    in(a,b);
    ll gcdv=__gcd(a,b);
    vector<pair<ll,ll>> prime=prime_factor(gcdv);
    out(prime.size()+1);
}
