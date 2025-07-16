#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<string>
#include<cmath>
#include<set>
#include<queue>
#include<deque>
#include<bitset>
#include<iomanip>
#include<cctype>
#include<map>
#include<cstring>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,a,b) for (int (i)=a;(i)<(b);(i)++)
#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long int;

const int inf = 1001001000;
const long long int Inf = 1001001001001001000;


void print(vector<vector<int>> a){
	for (int i = 0; i < a.size(); i++)
	{
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<vector<long long int>> a){
	for (int i=0;i<a.size();i++){
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<int> a){
    int n = a.size();
    for (int j=0;j<n;j++) {
        if (j != n-1) cout << a[j] << " ";
        else cout << a[j] << endl;
    }
}

void print(set<int> a){
	for (auto x:a)
		cout << x << " ";
	cout << endl;
}

//幅優先探索のテンプレ.デフォルトではstartからの距離を返す.
//graphは隣接リスト.startは探索開始地点
vector<int> bfs(vector<vector<int>> &graph, int start){
	queue<int> todo;
	vector<int> dist(graph.size(),-1);
	dist[start] = 0;
	todo.push(start);
	while(!todo.empty()){
		int now = todo.front();
		todo.pop();
		for (int i=0;i<graph[now].size();i++){
			int nxt = graph[now][i];
			if (dist[nxt] != -1) continue;
			dist[nxt] = dist[now] + 1;
			todo.push(nxt);
		}
	}
	return dist;
}

const int D = 80*160+10;
const int D2 = D*2;
typedef bitset<D2> bs;
 
int a[100][100];
bs dp[90][90];
 
int main() {
  int h, w;
  cin >> h >> w;
  rep(i,h)rep(j,w) {
    int x;
    cin >> x;
    a[i][j] = x;
  }
  rep(i,h)rep(j,w) {
    int x;
    cin >> x;
    a[i][j] = abs(x-a[i][j]);
  }
 
  dp[0][0][D-a[0][0]] = 1;
  dp[0][0][D+a[0][0]] = 1;
  rep(i,h)rep(j,w) {
    if (i) {
      dp[i][j] |= dp[i-1][j]<<a[i][j];
      dp[i][j] |= dp[i-1][j]>>a[i][j];
    }
    if (j) {
      dp[i][j] |= dp[i][j-1]<<a[i][j];
      dp[i][j] |= dp[i][j-1]>>a[i][j];
    }
  }
  int ans = D2;
  rep(i,D2) if (dp[h-1][w-1][i]) {
    ans = min(ans, abs(i-D));
  }
  cout << ans << endl;
  return 0;
}