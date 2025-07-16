#include<cstdio>
#include<queue>
#include<utility>

using namespace std;

typedef pair<int, int> P;

const int MAX_N = 400;

const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};

bool color[MAX_N][MAX_N];
int H, W;

char ch[MAX_N + 1];

void input(){
	scanf("%d%d", &H, &W);
	for(int i = 0; i < H; ++i){
		scanf("%s", ch);
		for(int j = 0; j < W; ++j){
			color[i][j] = (ch[j] == '#');
		}
	}
}

bool isin_(int i, int j){
	return i >= 0 && i < H && j >= 0 && j < W;
}

bool check_(int i, int j, int d){
	int ni = i + di[d];
	int nj = j + dj[d];
	if(!isin_(ni, nj)) return false;
	if(color[i][j] == color[ni][nj]) return false;
	return true;
}

bool used[MAX_N][MAX_N];

long long solve(){
	long long ans = 0;
	long long b = 0, w = 0;
	for(int i = 0; i < H; ++i){
		for(int j = 0; j < W; ++j){
			if(used[i][j]) continue;
			b = 0;
			w = 0;
			queue<P> que;
			used[i][j] = true;
			que.push(P(i, j));
			while(!que.empty()){
				P p = que.front();
				que.pop();
				int ci = p.first, cj = p.second;
				if(color[ci][cj]) b++;
				else w++;
				for(int d = 0; d < 4; ++d){
					if(!check_(ci, cj, d)) continue;
					int ni = ci + di[d], nj = cj + dj[d];
					if(used[ni][nj]) continue;
					used[ni][nj] = true;
					que.push(P(ni, nj));
				}
			}
			ans += b * w;
		}
	}
	return ans;
}

int main(){
	input();
	long long ans = solve();
	printf("%lld\n", ans);
	return 0;
}
