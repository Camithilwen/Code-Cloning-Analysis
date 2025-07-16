//0039
//include-------------------------------------
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<stack>

using namespace std;

//typedef--------------------------------------
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

#define MP make_pair

//repetition-----------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

//constant-------------------------------------
const double PI = acos(-1.0);

//cout,cin-------------------------------------
#define COUT(x) cout<<(x)<<endl
#define CIN(x) cin>>(x)

int f(char c){
	if (c == 'I') return 1;
	else if (c == 'V') return 5;
	else if (c == 'X') return 10;
	else if (c == 'L') return 50;
	else if (c == 'C') return 100;
	else if (c == 'D') return 500;
	else if (c == 'M') return 1000;
}

int main(){
	int ans = 0;
	string st;
	while (CIN(st)){
		 int now = f(st[0]);
		 if (st.size() == 1) ans = now;
		 ans = now;
		 REP(i, st.size() - 1){
			 now >= f(st[i + 1]) ? ans += f(st[i + 1]) : ans += f(st[i + 1]) - now - now;
			 now = f(st[i + 1]);
		 }
		 COUT(ans);
	}



	return 0;

}