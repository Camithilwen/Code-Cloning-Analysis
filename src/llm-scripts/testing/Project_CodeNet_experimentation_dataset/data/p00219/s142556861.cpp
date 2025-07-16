#include <iostream>
#define rep2(x,from,to) for(int x=(from);(x)<(to);(x)++)
#define rep(x,to) rep2(x,0,to)
using namespace std;
int main(){
	int n, m;
	while(cin >> n, n) {
		int cnt[10] = {};
		rep(i,n) {
			cin >> m;
			cnt[m]++;
		}
		rep(i,10) {
			if(cnt[i]==0) cout << "-";
			else {
				rep(j,cnt[i]) cout << "*";
			}
			cout << endl;
		}
	}
}