#include <iostream>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < n; i++)
using namespace std;

string s; int n;
int K;
int dp[300][300][301];	//dp[l][r][x] = 区間[l, r]内における最長回文の長さ（変更数≦x)
int iter[2][300][26];	//iter[left or right][pos][moji] = (leftの場合)s[pos],…,s[n-1]の間において文字mojiが出現する最初の場所
						//, (rightの場合)s[0],…,s[pos]の間において文字mojiが出現する最後の場所

int dfs(int l, int r, int x) {
	int len = r - l + 1;
	if (len == 1) return 1;
	if (len <= 0) return 0;
	if (dp[l][r][x] != -1) return dp[l][r][x];
	
	int ret = 0;
	if (x > 0 && len >= 2) ret = 2 + dfs(l + 1, r - 1, x - (s[l] != s[r]));
	
	for (int i = 0; i < 26; i++) {
		int nl = iter[0][l][i];
		int nr = iter[1][r][i];
		if (nl == -1 || nr == -1 || nl > nr) continue;
		int res = 2 - (nl == nr) + dfs(nl + 1, nr - 1, x);
		ret = max(ret, res);
	}
	return dp[l][r][x] = ret;
}

int main() {
	int i, j, k;
	
	cin >> s >> K;
	n = s.length();
	rep(i, n) rep(j, n) rep(k, n + 1) dp[i][j][k] = -1;
	rep(i, 2) rep(j, n) rep(k, 26) iter[i][j][k] = -1;
	
	rep(i, n) {
		for (j = i; j < n; j++) {
			if (iter[0][i][s[j] - 'a'] == -1) {
				iter[0][i][s[j] - 'a'] = j;
			}
		}
		for (j = i; j >= 0; j--) {
			if (iter[1][i][s[j] - 'a'] == -1) {
				iter[1][i][s[j] - 'a'] = j;
			}
		}
	}
	int res = dfs(0, n - 1, K);
	cout << res << endl;
	return 0;
}

//K=0の場合で実験すると、最長部分列のうち一つは回文になっていると予想できる。これが正しければ、最長回文の長さが解の上界になる。
//まあ、AGCなので正しいだろう（は？）
//また、Tの回文部分列なら何でも、TとT'の共通部分列になっている。よって、最長回文の長さが解の下界になる。
//
//よって、「文字列Sの文字をK文字まで変更できるとき、作れる回文部分列の長さは最大でいくらになるか？」という問題になる。
//これは、
//１．文字を変更する→（回文になるように）左から文字を選ぶ
//２．左から文字を選ぶ→（回文になるように）文字を変更する→変更数≦Kかをチェックする。
//３．両端から文字を選ぶ→（回文になるように）文字を変更する
//のいずれでも解くことができるが、３の方針で考えると見通しがよい。このとき、以下の問題を解くのが本質になる。
//
//「両端からペアを作っていく。1文字だけのペアも作れるが、ペアは入れ子構造になっている必要がある。
//ペアを作るとき、違う文字ならコストが1発生する。コストK以下でいくつペアを作れるか？」
//
//この問題は、dp[左端l][右端r][変更数x] = そこからいくつのペアを作れるか？というDPで解くことができる。
//遷移は、「両端(l, r)を使う」「コストを消費せず、文字aでペアを作る」の2つだが、どちらもO(1)で行うことができる。
//計算量はO(N^3) * 26 / 2くらいになる。これ間に合うのか？