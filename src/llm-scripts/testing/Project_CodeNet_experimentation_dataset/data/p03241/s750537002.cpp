#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

template <typename TYPE>
void print_vec(const vector<TYPE>& v){
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

template <typename TYPE>
void print_vec2(const vector<vector<TYPE>>& v){
  cout << endl; cout << "       ";
  for(int i=0; i<v[0].size(); i++) cout << i << "   "; 
  cout << endl;
	for(int i=0; i<v.size(); i++){
		cout << "i=" << i << ":   ";
		for(int j=0; j<v[i].size(); j++){
			if(v[i][j] == 0) cout << "\x1B[0m" << v[i][j] << "   ";
      else cout << "\x1B[31m" << v[i][j] << "   ";//https://stackoverrun.com/ja/q/12618775
		}
		cout << "\x1B[0m" << endl;
	}
}


using P = pair<int ,int>;
using LP = pair<ll, int>;
int main(){
	int N; 
	ll M;
	cin >> N >> M;

	vector<ll> divs;
	for(ll i=1; i*i<=M;  i++){
		if(M%i == 0){
			divs.push_back(i);
			if(i*i != M)divs.push_back(M/i);
		}
	}
	sort(divs.begin(), divs.end());
	ll ans = 0;
	for(int i=0; i<(int)divs.size(); i++){
		if(M/divs[i] >= N) ans = max(ans, divs[i]);
	}
	// cout << " divs: "; print_vec(divs);
	cout << ans << endl;


	// vector<LP> prime_divisors;
	// ll m = M;
	// //エラトステネスの篩
	// for(ll p=2; p*p<m; p++){
	// 	if(m % p != 0) continue;
	// 	int cnt = 0;
	// 	while(m%p == 0){
	// 		m /= p;
	// 		cnt++;
	// 	}
	// 	prime_divisors.emplace_back(p, cnt);
	// }
	// if(m != 1) prime_divisors.emplace_back(m, 1);


	// vector<ll> divs;// Mの因数となるモノを格納
	// ll ans = 0;

}

