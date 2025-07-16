#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
int n, k;
string s[][7] = {{"aacd","bbcd","cdaa","cdbb"}, {"aa.ab",".bbab","a.cca","a.a.a","bbabb"}, {"aacd..","bbcd..","cd..aa","cd..bb","..aacd","..bbcd"},{"aacd...","bbcd...","cd.aa..","cd...bb","..a.baa","..a.b.b","..bbaab"}};
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	k = n%4;
	if(n < 3) cout << -1 << '\n';
	else if(n == 3) cout << "aab\nb.b\nbaa\n";
	else rep(i,n){
		string b(n,'.');
		if(i<n-k-4) b.replace(i/4*4,4,s[0][i%4]);
		else b.replace(n-k-4,k+4,s[k][i-n+k+4]);
		cout << b << '\n';
	}
}