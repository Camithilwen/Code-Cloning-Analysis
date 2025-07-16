// #define _CRT_SECURE_NO_WARNINGS
// #define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <locale>
#include <cctype>
#include <sstream>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef map<int, int> MAPII;
typedef multimap<int, char, greater<int> > MuMAPIC;
typedef vector<pair<int, int> > VPII;
typedef multimap<int, string, greater<int> > MuMIS;

#define MP make_pair
#define fastIO  cin.tie(0); ios::sync_with_stdio(false);
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
//for gcc (未test)
// #define FOREACH_IT(it,c) for(typeof(c)::iterator it=(c).begin(); it!=(c).end(); ++it)
//for Visual Studio
#define foreach_it(type,it,c) for(type::iterator it=c.begin(),c_end=c.end();it!=c_end;++it)
#define DUMP_VVI(b) FOR(i,0,b.size()){FOR(j,0,b[i].size())printf("%d ",b[i][j]);puts("");}
int INPUT_INT() { int d; cin >> d; return d; } // 入力をpush_back(d)やarray[d]に使う時に無駄な変数を使わない

// ------------------- include, typedef, define END. -------------------

void solve(VI in){
	FOR(i, 0, in.size()){
		if (in[i]){
			while (in[i]--){
				cout << "*";
			}
			cout << endl;
		}
		else{
			cout << "-" << endl;
		}
	}
}

int main(){
	int n;
	while (cin >> n,n){
		VI input(10,0);
		FOR(i, 0, n){
			input[INPUT_INT()]++;
		}
		solve(input);
	}
	return 0;
}