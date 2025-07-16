const int isDebugMode = 0;
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
struct edge{long long to,cost;};
const int inf = 1 << 27;
const long long INF = 1LL << 60;
const int COMBMAX = 1001001;
const long long MOD = 1000000007;
const long long dy[] = {-1, 0, 0, 1};
const long long dx[] = {0, -1, 1, 0};
string abc = "abcdefghijklmnopqrstuvwxyz";
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define eachdo(v, e) for (const auto &e : (v))
#define all(v) (v).begin(), (v).end()
#define lower_index(v, e) (long long)distance((v).begin(), lower_bound((v).begin(), (v).end(), e))
#define upper_index(v, e) (long long)distance((v).begin(), upper_bound((v).begin(), (v).end(), e))
long long mpow(long long a, long long n, long long mod = MOD){long long res = 1; while(n > 0){if(n & 1)res = res * a % mod; a = a * a % mod; n >>= 1;} return res;}
void pt(){cout << endl; return;}
template<class Head> void pt(Head&& head){cout << head; pt(); return;}
template<class Head, class... Tail> void pt(Head&& head, Tail&&... tail){cout << head << " "; pt(forward<Tail>(tail)...);}
void dpt(){if(!isDebugMode) return; cout << endl; return;}
template<class Head> void dpt(Head&& head){if(!isDebugMode) return; cout << head; pt(); return;}
template<class Head, class... Tail> void dpt(Head&& head, Tail&&... tail){if(!isDebugMode) return; cout << head << " "; pt(forward<Tail>(tail)...);}
template<class T> void debug(T v){if(!isDebugMode) return; rep(i, v.size()) cout << v[i] << " " ; cout << endl;}
template<class T> void debug2(T v){if(!isDebugMode) return; rep(i, v.size()){rep(j, v[i].size()) cout << v[i][j] << " " ; cout << endl;}}
template<class T1, class T2> inline bool chmin(T1 &a, T2 b){if(a > b){a = b; return true;} return false;}
template<class T1, class T2> inline bool chmax(T1 &a, T2 b){if(a < b){a = b; return true;} return false;}
template<class T1, class T2> long long gcd(T1 a, T2 b){return a % b ? gcd(b , a % b) : b;}
template<class T1, class T2> void reduce(T1 &a, T2 &b){ll g = gcd(a, b); a /= g; b /= g; return;}
bool valid(long long H, long long W, long long h, long long w) { return 0 <= h && h < H && 0 <= w && w < W; }

int main(){
    string S; cin >> S;
    string cba = abc;
    reverse(all(cba));
    if (S == cba){
        pt(-1);
        return 0;
    }
    if(S.size() == 26){
        for(ll i = 25; 0 < i; i--){
            if(S[i] - 'a' > S[i - 1] - 'a'){
                ll lim = S[i - 1] - 'a';
                ll cnt = INF; 
                for(ll j = i; j < 26; j++){
                    if(lim < S[j] - 'a') chmin(cnt, S[j] - 'a');
                }
                S[i - 1] = abc[cnt];
                pt(S.substr(0, i));
                return 0;
            }
        }
    }else{
        for(auto e : abc){
            if(find(all(S), e) == S.end()){
                S += e;
                pt(S);
                return 0;
            }
        }
    }
    return 0;
}