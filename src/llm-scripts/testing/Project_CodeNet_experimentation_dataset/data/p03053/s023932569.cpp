//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INTINF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

//二次元平面を探索しよう
template <typename T,typename U>                                                   
std::pair<T,U> operator+(const std::pair<T,U> & l,const std::pair<T,U> & r) {   
    return {l.first+r.first,l.second+r.second};                                    
} 

vector<pair<int, int>> nei;
void nei_init(){
	nei.push_back(make_pair(-1,0));nei.push_back(make_pair(1,0));nei.push_back(make_pair(0,-1));nei.push_back(make_pair(0,1));
	//4近傍ならコメントアウト
	//nei.push_back(make_pair(-1,-1));nei.push_back(make_pair(1,-1));nei.push_back(make_pair(1,1));nei.push_back(make_pair(-1,1));
}

bool is_safe(pair<int, int> p, int h, int w){
	if(p.first < 0 || p.second < 0) return false;
	else if(p.first >=h || p.second >=w) return false;
	else return true;
}
//

int main() {
	int ans = 0;
	int tmp;
	nei_init();
	int h, w;
	cin >> h >> w;
	vector<string> mp(h);
	REP(i, h) cin >> mp[i];
	queue<pair<pair<int, int>,int> > q;
	bool ch[h][w] ={};
	int count = h*w;
	REP(i, h) REP(j, w) if(mp[i][j] == '#'){
		q.push(make_pair(make_pair(i, j),1));
		ch[i][j] = true;
		count--;
	}
	pair<int, int> now;
	int ope;
	while(!q.empty() && count > 0){
		now = q.front().first;
		ope = q.front().second;
		q.pop();
		ans = max(ans, ope);
		REP(i, nei.size()){
			pair<int, int> see = make_pair(now.first+nei[i].first, now.second+nei[i].second); 
			if(is_safe(see, h, w) && !ch[see.first][see.second]){
				q.push(make_pair(see, ope+1));
				ch[see.first][see.second] = true;
				count--;
			}
		}
	}
	cout << ans << endl;
}