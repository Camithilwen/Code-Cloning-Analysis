#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//Write From this Line

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int> (n-1));
	rep(i,n){
		rep(j,n-1){
			cin >> a[i][j];
			a[i][j]--;
		}
		reverse(a[i].begin(), a[i].end());
	}

	vector<P> q;
	auto check = [&](int i){
		if(a[i].size() == 0) return;
		int j = a[i].back();
		if(a[j].size() == 0) return;
		if(a[j].back() == i){
			P p(i,j);
			if(p.second < p.first) swap(p.first, p.second);
			q.push_back(p);
		}
	};
	rep(i,n){
		check(i);
	} 
	int day = 0;
	while(q.size() > 0){
		day++;
		sort(q.begin(), q.end());
		q.erase(unique(q.begin(), q.end()), q.end());
		vector<P> prevQ;
		swap(prevQ, q);
		
		for(P p: prevQ){
			int i = p.first, j = p.second;
			a[i].pop_back();
			a[j].pop_back();
		}
		for(P p: prevQ){
			int i = p.first, j = p.second;
			check(i);
			check(j);
		}
	}
	rep(i,n){
		if(a[i].size() != 0){
			cout << -1 << endl;
			return 0;
		}
	}
	cout << day << endl;
}

