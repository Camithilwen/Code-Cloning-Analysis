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

int main(){
	int N;
	cin >> N;
	vector<ll> A(N);
	int num_minus = 0;
	for(int i=0; i<N; i++){
		ll a;
		cin >> a;
		if(a<0){
			num_minus++;
			a *= -1;
		}
		A[i] = a;
	}
	
	sort(A.rbegin(), A.rend());
	ll ans = 0;
	for(int i=0; i<N; i++) ans += A[i];
	if(num_minus % 2 ==1) ans -= 2*A.back();
	cout << ans << endl;
	
	return 0;
}

