#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <limits>
typedef long long ll;
#define REP(i,n)   for(int i=0; i<(int)(n); ++i)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); ++i)

#define in cin
#define out cout
#define pb push_back
using namespace std;

int main(){
	int a[4], b[2], mi = 999, sum=0;
	REP(i, 4) {
		in >> a[i];
		sum += a[i];
		mi = min(mi, a[i]);
	}
	in >> b[0];
	in >> b[1];
	int bb = max(b[0], b[1]);
	sum -= mi;

	
	out << sum+bb << endl;
	return 0;

}