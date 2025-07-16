// #define _CRT_SECURE_NO_WARNINGS
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
typedef vector<pair<int, int> > VPII;
typedef multimap<int, string, greater<int> > MuMIS;

#define MP make_pair
#define fastIO	cin.tie(0); ios::sync_with_stdio(false);
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
//for gcc (未test)
// #define FOREACH_IT(it,c)	for(typeof(c)::iterator it=(c).begin(); it!=(c).end(); ++it)
//for Visual Studio
#define foreach_it(type,it,c) for(type::iterator it=c.begin(), c_end=c.end(); it!=c_end; ++it)

// ------------------- include, typedef, define END. -------------------

int Hit(int *rui){
	rui[0]++;
	// 塁を進める
	FOR(i, 1, 4){
		if (rui[i - 1]==2){
			rui[i]++;
			rui[i - 1] = 1;
		}
	}
	if (rui[3]!=0){
		rui[3] = 0;
		return 1;
	}
	return 0;
}

int Homerun(int *rui){
	int ret = 1;
	FOR(i, 0, 4)
		if (rui[i])
			ret++;
	return ret;
}

int main(){
	fastIO;
	int n, outCount = 0, tokuten = 0;
	string in;
	// rui[0]〜rui[2] = 1塁〜3塁, rui[3] = 本塁
	// 各値はその塁にいる人数(0〜2)
	int rui[4] = {};
	cin >> n;
	while (cin >> in){
		if (in == "OUT")
			outCount++;
		if (outCount < 3){
			if (in == "HIT"){
				tokuten += Hit(rui);
			}
			else if (in == "HOMERUN"){
				tokuten += Homerun(rui);
				FOR(i, 0, 4)	rui[i] = 0;
			}
		}
		else{
			cout << tokuten << endl;
			FOR(i, 0, 4)	rui[i] = 0;
			tokuten = 0;
			outCount = 0;
		}
	}
	return 0;
}