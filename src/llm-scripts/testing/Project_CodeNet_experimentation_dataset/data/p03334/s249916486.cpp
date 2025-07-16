#include <bits/stdc++.h>
using namespace std;
int N, D1, D2, M;
int A1[610][610], A2[610][610]; 
vector<pair<int, int>> v1, v2;
vector<pair<int, int>> V[4]; 
void dfs1(int x, int y, int c){
	A1[x][y] = c; 
	for(auto p : v1){
		int nx = x + p.first; int ny = y + p.second; 
		if(nx < 0 || nx > M || ny < 0 || ny > M) continue; 
		if(A1[nx][ny]) continue; 
		dfs1(nx, ny, 3 - c); 	
	}
}
void dfs2(int x, int y, int c){
	A2[x][y] = c; 
	for(auto p : v2){
		int nx = x + p.first; int ny = y + p.second; 
		if(nx < 0 || nx > M || ny < 0 || ny > M) continue; 
		if(A2[nx][ny]) continue; 
		dfs2(nx, ny, 4 - c); 	
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 
	cin >> N >> D1 >> D2; 
	M = 2 * N - 1; 
	for(int i = -M; i <= M; i++){
		for(int j = -M; j <= M; j++){
			int d = i * i + j * j;
			if(d == D1) v1.emplace_back(i, j); 
			if(d == D2) v2.emplace_back(i, j); 
		}
	}
	for(int i = 0; i <= M; i++){
		for(int j = 0; j <= M; j++){
			if(!A1[i][j]) dfs1(i, j, 1); 
			if(!A2[i][j]) dfs2(i, j, 1);  
		}
	}
	for(int i = 0; i <= M; i++){
		for(int j = 0; j <= M; j++){
			int t = A1[i][j] + A2[i][j] - 2; 
			V[t].emplace_back(i, j); 
		}
	}
	int idx = -1; 
	for(int t = 0; t < 4; t++){
		if(V[t].size() >= N * N) idx = t; 
	}
	for(int i = 0; i < N * N; i++){
		cout << V[idx].at(i).first << " " << V[idx].at(i).second << "\n"; 
	}
}