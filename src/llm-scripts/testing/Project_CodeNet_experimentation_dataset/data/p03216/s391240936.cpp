#include <bits/stdc++.h>

using namespace std;
#define FOR(i,o,n) for(long long i = o;i<n;i++)
#define oneforall ios::sync_with_stdio(false);cin.tie(0);
#define all(v) (v).begin(),(v).end()
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) long long __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
#define int long long
const long long INF=1e18;
void in(){} template <typename T,class... U> void in(T &t,U &...u){ cin >> t; in(u...);}
void out(){cout << "\n";} template <typename T,class... U> void out(const T &t,const U &...u){ cout << t; if(sizeof...(u)) cout << " "; out(u...);}
typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;
typedef vector<pair<long, long > > vpll;
typedef vector<pair<int, int > > vpii;


ll mo=1000000007;
ll comb(ll N_, ll C_) {
    const int NUM_=310000;
    static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
    if (fact[0]==0) {
        inv[1]=fact[0]=factr[0]=1;
        for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
        for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
    }
    if(C_<0 || C_>N_) return 0;
    return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}
int32_t main() {
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    
    ini(n);
    ins(morty);
    ini(n1);
    FOR(i,0,n1){
        ini(x);
        int d = 0;
        int m = 0;
        int dm = 0;
        int tmp = 0;
        int i1 = 0;
        FOR(i,0,n){
            if(morty[i] == 'D')d++;
            else if(morty[i] == 'M'){
                m++;
                dm+=d;
            }
            else if(morty[i] == 'C'){
                tmp+=dm;
            }
            if(i>=x-1){
                if(morty[i1] == 'D'){
                    dm-=m;
                    d--;
                }
                else if(morty[i1] == 'M')m--;
                i1++;
            }
        }
        out(tmp);
    }
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
