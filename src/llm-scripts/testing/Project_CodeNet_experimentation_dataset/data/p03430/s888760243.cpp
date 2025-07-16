#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
 
#define ALL(obj) (obj).begin(),(obj).end()
#define SPEED cin.tie(0);ios::sync_with_stdio(false);
 
template<class T> using PQ = priority_queue<T>;
template<class T> using PQR = priority_queue<T,vector<T>,greater<T>>;
 
constexpr long long MOD = (long long)1e9 + 7;
constexpr long long MOD2 = 998244353;
constexpr long long HIGHINF = (long long)1e18;
constexpr long long LOWINF = (long long)1e15;
constexpr long double PI = 3.1415926535897932384626433;
 
template <class T> vector<T> multivector(size_t N,T init){return vector<T>(N,init);}
template <class... T> auto multivector(size_t N,T... t){return vector<decltype(multivector(t...))>(N,multivector(t...));}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) {o << "{"; for (auto &x : obj) o << " {" << x.first << " : " << x.second << "}" << ","; o << " }"; return o;}
template <class T>ostream &operator<<(ostream &o, const set<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const multiset<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) {o << "{"; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "}"; return o;}
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) {o << "{" << obj.first << ", " << obj.second << "}"; return o;}
void print(void) {cout << endl;}
template <class Head> void print(Head&& head) {cout << head;print();}
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) {cout << head << " ";print(forward<Tail>(tail)...);}
template <class T> void chmax(T& a, const T b){a=max(a,b);}
template <class T> void chmin(T& a, const T b){a=min(a,b);}
void YN(bool flg) {cout << (flg ? "YES" : "NO") << endl;}
void Yn(bool flg) {cout << (flg ? "Yes" : "No") << endl;}
void yn(bool flg) {cout << (flg ? "yes" : "no") << endl;}


int main() {
	SPEED
	string S; cin >> S;
	int N = S.size();
	int K; cin >> K;
	auto R = multivector(N, 26,-1);
	auto L = multivector(N, 26,-1);
	vector<int> cnt(26,-1);
	for(int i = 0; i < N; ++i) {
		L[i] = cnt;
		cnt[S[i]-'a'] = i;
	}
	for(int a = 0; a < 26; ++a){
		cnt[a] = -1;
	}
	for(int i = N-1; 0 <= i; --i) {
		R[i] = cnt;
		cnt[S[i]-'a'] = i;
	}
	auto dp = multivector((K+2)*N*N,0);
	for(int i = 0; i < N; ++i) {
		for(int k = 0; k <= K; ++k) {
			dp[k*N*N+i*N+i] = 1;
		}
	}
	for(int i = 0; i+1 < N; ++i) {
		for(int k = 0; k <= K; ++k) {
			if(S[i]==S[i+1]) dp[k*N*N+i*N+i+1] = 2;
			else dp[k*N*N+i*N+i+1] = (k?2:0);
		}
	}
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j + i < N; ++j){
			int l = j, r = j + i;
			for(int k = 0; k <= K; ++k) {
				//コストが発生しないとき
				for(int a = 0; a < 26; ++a){
					int x = L[l][a],y = R[r][a];
					if(x==-1||y==-1) continue;
					chmax(dp[k*N*N+x*N+y],dp[k*N*N+l*N+r]+2);
				}
				//コストが発生するとき
				if(0<=l-1&&r+1<N) chmax(dp[(k+1)*N*N+(l-1)*N+r+1],dp[k*N*N+l*N+r]+2);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j){
			for(int k = 0; k <= K; ++k) {
				chmax(ans,dp[k*N*N+i*N+j]);
			}
		}
	}
	cout << ans << endl;
    return 0;
}