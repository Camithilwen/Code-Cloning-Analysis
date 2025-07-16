#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	string S;
	cin >> S;
	vector<bool> alpha(26);
	int N = S.size();
	string s = "abcdefghijklmnopqrstuvwxyz";
	rep(i,N){
		alpha[S[i] - 'a'] = true;
	}
	rep(i,26){
		if(alpha[i] == false){
			cout << s[i] << endl;
			return 0;
		}
	}
	 cout << "None" << endl;
	 return 0;
}










