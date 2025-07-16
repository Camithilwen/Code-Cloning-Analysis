#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	map<int, int> odd, even;
	int odd_first = 0, odd_second = 0;
	int odd_first_num = -1, odd_second_num = -1;
	int even_first = 0, even_second = 0;
	int even_first_num = -1, even_second_num = -1;
	rep(i,n){
		int v;
		cin >> v;
		if(i%2){
			++even[v];
			if(even[v] > even_first){
				if(even_first_num != v){
					even_second = even_first;
					even_second_num = even_first_num;
				}
				even_first = even[v];
				even_first_num = v;
			}
			else if(even[v] > even_second){
				even_second = even[v];
				even_second_num = v;
			}
		}
		else{
			++odd[v];
			if(odd[v] > odd_first){
				if(odd_first_num != v){
					odd_second = odd_first;
					odd_second_num = odd_first_num;
				}
				odd_first = odd[v];
				odd_first_num = v;
			}
			else if(odd[v] > odd_second){
				odd_second = odd[v];
				odd_second_num = v;
			}
		}
	}
	/*
	cout << odd_first_num << " " << odd_first << endl;
	cout << even_first_num << " " << even_first << endl;
	cout << odd_second << endl;
	cout << even_second << endl;
	*/
	int ans = 1e9;
	if(odd_first_num != even_first_num){
		chmin(ans, n - odd_first - even_first);
	}
	else{
		chmin(ans, n - odd_first - even_second);
		chmin(ans, n - odd_second - even_first);
	}
	cout << ans << endl;
	return 0;
}