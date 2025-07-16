#include <bits/stdc++.h>
using namespace std;
int main(){
	int N; string S; cin >> N >> S; 
	string first[262200] = {}, second[262200] = {}; 
	for(int i = 0; i < (1 << N); i++){
		string tmp1, tmp2; 
		for(int j = 0; j < N; j++){
			if((i >> j) & 1) tmp1.push_back(S.at(j)); 
			else tmp2.push_back(S.at(j)); 
		}
		reverse(tmp2.begin(), tmp2.end()); 
		first[i] = tmp1 + '1' + tmp2; 
	}
	for(int i = 0; i < (1 << N); i++){
		string tmp1, tmp2; 
		for(int j = 0; j < N; j++){
			if((i >> j) & 1) tmp1.push_back(S.at(N+j)); 
			else tmp2.push_back(S.at(N+j)); 
		}
		reverse(tmp2.begin(), tmp2.end()); 
		second[i] = tmp2 + '1' + tmp1; 
	}
	sort(second, second + (1 << N)); 
	long long int ans = 0;
	for(int i = 0; i < (1 << N); i++){
		ans += upper_bound(second, second + (1 << N), first[i]) - lower_bound(second, second + (1 << N), first[i]); 
	}
	cout << ans << endl; 
}