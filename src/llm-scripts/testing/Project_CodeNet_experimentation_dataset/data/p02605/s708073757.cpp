#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair <int , int> pii;
const int MAXN = 4e5 + 10 , INF = 202020;
int ans = 1e9;
vector <pii> v[MAXN];
int x[MAXN] , y[MAXN] , t[MAXN];
int tu(char c){
	if(c == 'U') return 0;
	else if(c == 'R') return 1;
	else if(c == 'D') return 2;
	return 3;
}
void check(int m){
	for(int i = 0 ; i <= 400000 ; ++ i)
		if((int)v[i].size() > 0){
			sort(v[i].begin() , v[i].end());
			int la = -INF;
			for(int k = 0 ; k < (int)v[i].size() ; ++ k)
				if(v[i][k].second == -1){
					if(la != -INF)
						ans = min(ans , (v[i][k].first - la) * m);
				}
				else
					la = v[i][k].first;
			v[i].resize(0);
		}
}
int main(){
	int N;
	scanf("%d" , &N);
	for(int i = 1 ; i <= N ; ++ i){
		char s[2];
		scanf("%d%d%s" , &x[i] , &y[i] , s);
	//	cout << i << " " << x[i] + y[i] << " " << x[i] - y[i] << " " << t[i] << endl; 
		t[i] = tu(s[0]);
	}
	for(int i = 1 ; i <= N ; ++ i)
		if(t[i] % 2 == 0)
			v[x[i]].push_back(make_pair(y[i] , (t[i] == 0 ? 1 : -1)));
	check(5);
	for(int i = 1 ; i <= N ; ++ i)
		if(t[i] % 2 == 1)
			v[y[i]].push_back(make_pair(x[i] , (t[i] == 1 ? 1 : -1)));
	check(5);
	for(int i = 1 ; i <= N ; ++ i)
		if(t[i] == 0 || t[i] == 3)
			v[y[i] - x[i] + 200000].push_back(make_pair(x[i] , (t[i] == 0 ? 1 : -1)));
	check(10);
	for(int i = 1 ; i <= N ; ++ i)
		if(t[i] == 1 || t[i] == 2)
			v[y[i] - x[i] + 200000].push_back(make_pair(x[i] , (t[i] == 1 ? 1 : -1)));
	check(10);
	for(int i = 1 ; i <= N ; ++ i)
		if(t[i] == 0 || t[i] == 1)
			v[x[i] + y[i]].push_back(make_pair(x[i] , (t[i] == 1 ? 1 : -1)));
	check(10);
	for(int i = 1 ; i <= N ; ++ i)
		if(t[i] == 2 || t[i] == 3)
			v[x[i] + y[i]].push_back(make_pair(x[i] , (t[i] == 2 ? 1 : -1)));
	check(10);
	if(ans == 1e9)
		cout << "SAFE" << endl;
	else
		cout << ans << endl;
	return 0;
}