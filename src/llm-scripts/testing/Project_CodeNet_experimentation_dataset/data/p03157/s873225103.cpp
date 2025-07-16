#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

typedef long long LL;

const int MAXN=400;

LL n, m, ans, cntW, cntB;
bool visited[MAXN][MAXN];
string s[MAXN];

bool avail(int i, int j, char c){
	if(i < 0 || i >= n || j < 0 || j >= m) return false;
	if(s[i][j] == c) return false;
	return true;
}

void dfs(int i, int j){
	if(i < 0 || i >= n || j < 0 || j >= m) return;
	if(visited[i][j]) return;

	visited[i][j] = true;
	if(s[i][j] == '.') cntW++;
	else cntB++;
	if(avail(i, j - 1, s[i][j])) dfs(i, j - 1);
	if(avail(i, j + 1, s[i][j])) dfs(i, j + 1);
	if(avail(i + 1, j, s[i][j])) dfs(i + 1, j);
	if(avail(i - 1, j, s[i][j])) dfs(i - 1, j);
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> s[i];

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			visited[i][j] = false;

	ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(!visited[i][j]){
				cntB = 0; cntW = 0;

				dfs(i, j);
				ans += cntB * cntW;
			}
	cout << ans << "\n";
}