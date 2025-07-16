//int a = s - '0'; 文字から数字
//小文字から大文字
//transform(a.begin(), a.end(), a.begin(), ::toupper);
//map 全探索
//auto begin = p.begin(), end = p.end();
//for (auto it = begin; it != end; it++) {}
//mapのキー：it->first mapのバリュー：it->second
//大文字判定 isupper(文字) 小文字判定 islower(文字)
//do{}while(next_permutation(ALL(配列)))
//小文字に対応する文字コード：S[i] - 'a'
//文字コード→小文字：(char)(数字+'a')
//グラフの距離:隣接行列で扱う
//bool型　初期値はTrue
//島渡りの問題：中間ノードに着目
//数が大きい時の比較はstring型で行う
//全て0になったか調べたい->0になるたびにcntする
//例外処理は最初にする
//x = p^m + q^n...の約数の個数:(n+1)*(m+1)....
//N!のどの素因数で何回割れるか
//⇔1~Nまでの数がそれぞれどの素因数で何回割り切れるかの和
//パズルの問題->一般化して全探索
//stack<ll> s;
//s.push(要素);s.top();s.pop();
//queue<ll> q;
//q.push(要素);q.front();q.pop();
//同じ作業繰り返す系の問題：収束先を見つける
//過半数：N/2.0で判定
//優先度付きキュー
//priority_queue<
//ll,
//vector<ll>
//> q;
#include <bits/stdc++.h>
#define rep(i,N) for(int i = 0; i < N;i++)
#define ALL(a) (a).begin(),(a).end()
#define ll long long int
#define PI 3.14159265358979323846264338327950L
using namespace std;

//割るやつ
const ll MOD = (pow(10, 9) + 7);

// K進数でのNの桁数
ll dig(ll N, ll K) {
	ll dig = 0;
	while (N) {
		dig++;
		N /= K;
	}
	return dig;
}
// a,bの最大公約数
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

//a,bの最小公倍数
ll lcm(ll a, ll b) {
	ll g = gcd(a, b);
	return a / g * b;
}

//階乗計算
ll f(ll n) {
	if (n == 0 || n == 1) return 1;
	else return (n * f(n - 1));
}

//Nのd桁目の数
ll dignum(ll N, ll d) {
	ll x = pow(10, d);
	N %= x;
	ll y = pow(10, d - 1);
	N /= y;
	return N;
}

//Nをdで何回割れるか
ll divcnt(ll N, ll d) {
	ll ans = 0;
	while (1) {
		if (N%d == 0) {
			ans++;
			N /= d;
		}
		else break;
	}

	return ans;
}

//素数判定
bool prime(ll num) {
	if (num < 2) return false;
	else if (num == 2) return true;
	else if (num % 2 == 0) return false;
	double sqrtNum = sqrt(num);
	for (int i = 3; i <= sqrtNum; i += 2) {
		if (num % i == 0) return false;
	}
	return true;
}

//フィボナッチ数列
vector<ll> memo(pow(10, 6) + 1);
ll fibo(ll n) {
	if (n == 1) return 1;
	else if (n == 2) return 1;
	else if (memo[n] != 0) return memo[n];
	else return memo[n] = fibo(n - 1) + f(n - 2);
}

ll RS(ll N, ll P, ll M) {
	if (P == 0) return 1;
	if (P % 2 == 0) {
		ll t = RS(N, P / 2, M);
		return t * t % M;
	}
	return N * RS(N, P - 1, M);
}

vector<int> IntegerToVector(int bit, int N) {
    vector<int> S;
    for (int i = 0; i < N; ++i) {
        if (bit & (1 << i)) {
            S.push_back(i);
        }
    }
    return S;
}

int main() {
	ll N, M;cin >> N >> M;
	vector<ll> L(M), R(M);
	rep(i,M) cin >> L[i] >> R[i];

	sort(ALL(L));
	sort(ALL(R));


	if(R[0] - L[M-1] + 1 < 0) cout << 0 << endl;
	else cout << R[0] - L[M-1] + 1 << endl; 
}	