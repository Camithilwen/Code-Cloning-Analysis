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
	int N, M;
	cin >> N >> M;

	if(N % 2 == 1){
		for(int i=1; i<=M; i++){
			cout << i << " " << N-i+1 << endl;
		}
		return 0;
	}

	//以下Nが偶数の場合 
	//b-a==N/2にならないように途中で1ずらして表示　例(N, M) = (6,2)で影響
	//あるいは 前回のa,bの差と 今回のa,bの差の合計がNにならないように途中で1ずらして表示 例(N, M) = (8, 3)で影響
	int tmp = 0;
	for(int i=1; i<=M; i++){
		if(tmp==0 &&  (N-i+1)-(i) == N/2) tmp++;
		if(tmp==0 && (N-i+2)-(i-1) + (N-i+1)-i == N) tmp++;
		cout << i << " " << N-i+1-tmp << endl;
	}
	return 0;
}
