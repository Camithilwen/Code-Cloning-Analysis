#include<iostream>
#include<map>
#include<vector>
#include<list>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<climits>
#include<ctime>
#include<cstring>
#define REP(i,p,n) for(int i=p;i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define rep_split(tok,a_str,re) for(char *tok = strtok((char *)a_str.c_str(),re); tok != NULL; tok = strtok(NULL,re))
#define ALL(c) (c).begin(), (c).end()
#define dump(a) cerr << #a << "=" << (a) << endl

template<class T> void chmin(T &t, T f) { if (t > f) t = f; } //t=min 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } //t=max

using namespace std;

int main() {
	int N,Q;
	int M,date;
	bool dates[100][50]; //date N

	while(cin >> N >> Q) {
		if (N == 0 && Q == 0) break;
		fill_n((bool *)dates,sizeof(dates)/sizeof(bool),false);
		rep(n,N) {
			cin >> M;
			rep(m,M) { //Dates
				cin >> date;
				dates[date][n] = true;
			}
		}

		/*
		rep(n,N) {
			rep(d,20) {
				cout << dates[d][n];
			}
			cout << endl;
		}
		cout << endl; */

		int cnt=0;
		int max_cnt=0;
		int max_d=0;
		rep(d,100) {
			cnt = 0;
			rep(n,N) { //縦に見る
				if(dates[d][n]) {
					cnt++;
				}
			}
			if (cnt > max_cnt) {
				max_cnt = cnt;
				max_d = d;
			}
		}
		if (max_cnt >= Q) {
			cout << max_d << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
	

	return 0;
}