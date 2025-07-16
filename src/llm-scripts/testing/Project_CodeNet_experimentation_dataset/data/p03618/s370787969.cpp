#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long tint;
typedef long double ld;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend() 
#define NACHO ios::sync_with_stdio(0); cin.tie(NULL);
#define dbg cout << "hu" << endl;

const int INF = 50000001;
const int MOD = 1000000007;

//impossible pairs: (a^3, 1) (a^2, a^1)

int main(){
	string s; cin >> s;
	int n = s.size();
	tint quan = tint(n)*tint(n-1)/2;
	vector<int> cont (26, 0);
	forn(i, n){
		cont[s[i]-'a']++;
	}
	tint ret = 0;
	forn(i, 26){
		if(cont[i]) ret+=(tint(cont[i])*tint(cont[i]-1))/2;
	}
	cout << quan-ret+1 << endl;
}

