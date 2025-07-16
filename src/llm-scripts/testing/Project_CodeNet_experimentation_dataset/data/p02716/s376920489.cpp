#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define ALL(obj) (obj).begin(),(obj).end()
#define SPEED cin.tie(0);ios::sync_with_stdio(false);

template<class T> using PQ = priority_queue<T>;
template<class T> using PQR = priority_queue<T,vector<T>,greater<T>>;

constexpr long long MOD = (long long)1e9 + 7;
constexpr long long MOD2 = 998244353;
constexpr long long HIGHINF = (long long)1e18;
constexpr long long LOWINF = (long long)1e15;
constexpr long double PI = 3.1415926535897932384626433L;

template <class T> vector<T> multivector(size_t N,T init){return vector<T>(N,init);}
template <class... T> auto multivector(size_t N,T... t){return vector<decltype(multivector(t...))>(N,multivector(t...));}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) {o << "{"; for (auto &x : obj) o << " {" << x.first << " : " << x.second << "}" << ","; o << " }"; return o;}
template <class T>ostream &operator<<(ostream &o, const set<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const multiset<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) {o << "{"; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "}"; return o;}
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) {o << "{" << obj.first << ", " << obj.second << "}"; return o;}
template <template <class tmp>  class T, class U> ostream &operator<<(ostream &o, const T<U> &obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr)o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
void print(void) {cout << endl;}
template <class Head> void print(Head&& head) {cout << head;print();}
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) {cout << head << " ";print(forward<Tail>(tail)...);}
template <class T> void chmax(T& a, const T b){a=max(a,b);}
template <class T> void chmin(T& a, const T b){a=min(a,b);}
void YN(bool flg) {cout << (flg ? "YES" : "NO") << endl;}
void Yn(bool flg) {cout << (flg ? "Yes" : "No") << endl;}
void yn(bool flg) {cout << (flg ? "yes" : "no") << endl;}

ll f(vector<ll> A,int N) {
	A.push_back(0);
	reverse(ALL(A));
	auto dp = multivector(3,N+1,-LOWINF);
	dp[0][0]=0;
	dp[0][1]=A[1];
	for(int i = 1; i <= N; ++i) {
		for(int j = 0; j < 3; ++j) {
			for(int k = 1; k <= 3; ++k) {
				if(0<=i-1-k&&j+k-1<3) chmax(dp[j+k-1][i],dp[j][i-1-k]+A[i]);
			}
		}
	}
	ll ans;
	if(N%2==0) ans=max({dp[0][N],dp[0][N-1],dp[1][N]});
	else ans=max({dp[1][N],dp[1][N-1],dp[2][N]});
	return ans;
}
int main() {
	int N; cin >> N;
	vector<ll> A(N+1,0);
	for(int i = 1; i <= N; ++i) cin >> A[i];
	vector<map<int,ll>> dp1(N+1); //最後にiを使ってない
	vector<map<int,ll>> dp2(N+1); //最後にiを使った
	dp1[0][0]=0;
	for(int i = 1; i <= N; ++i) {
		int M = i/2;
		for(int j = -3+M; j <= M+3; ++j) {
			dp1[i][j]=dp2[i][j]=-LOWINF;
			if(dp1[i-1].count(j)) chmax(dp1[i][j],dp1[i-1][j]);
			if(dp1[i-1].count(j-1)) chmax(dp2[i][j],dp1[i-1][j-1]+A[i]);
			if(dp2[i-1].count(j)) chmax(dp1[i][j],dp2[i-1][j]);
		}
	}
	cout << max(dp1[N][N/2],dp2[N][N/2]) << endl;
    return 0;
}
