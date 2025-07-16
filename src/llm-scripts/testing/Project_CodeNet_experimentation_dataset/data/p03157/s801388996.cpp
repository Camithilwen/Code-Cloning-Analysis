#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;
vector<vector<bool>> used(500,vector<bool>(500,false));
P bfs(int N,int M,vector<string> field,int sx,int sy){
    int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
    queue<P> que;
    que.push(P(sx,sy));
	used[sx][sy] = true;
	P ans = mp(0,0);
	if (field[sx][sy] == '.'){
		ans.fs++;
	}
	else{
		ans.sc++;
	}
    //キューが空になるまでループ
    while(que.size()){
        P p = que.front();
        que.pop();//先頭を取り出す
        for (int i = 0;i < 4;i++){
            int nx = p.fs + dx[i], ny = p.sc + dy[i];
            //nx,nyが進めるマスか、行ったことのないマスかどうかを判定
			if (field[p.fs][p.sc] == '.'){
 				if (0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny] != '.' && !used[nx][ny]){
                	que.push(P(nx,ny));//追加
                	used[nx][ny] = true;
					ans.sc++;
           		}
			}
			else{
				if (0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny] != '#' && !used[nx][ny]){
                	que.push(P(nx,ny));//追加
                	used[nx][ny] = true;
					ans.fs++;
            	}
			}
        }
    }
	return ans;
}
int main(){
	int h,w;cin>>h>>w;
	vector<string> s(h);
	for(int i = 0; i < h; i++) {
		cin>>s[i];
	}
	ll ans = 0;
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			if (!used[i][j]){
				P res = bfs(h,w,s,i,j);
				ans += (res.fs * res.sc);
			}
		}
	}
	cout << ans << endl;
	return 0;
}