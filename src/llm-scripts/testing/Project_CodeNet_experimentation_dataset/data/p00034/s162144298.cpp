#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <climits>
 
#define REP(i,b,n) for(int i=b;i<n;++i)
#define REPR(i,b,n) for(int i=n-1;i>=b;--i)
#define CLR(mat) memset(mat, 0, sizeof(mat))
#define NCLR(mat) memset(mat, -1, sizeof(mat))
#define EACH(i, c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define EXIST(s, e) ((s).find(e) != (s).end())
#define BIT(n, b) ((n>>b) & 1)
#define PI acos(-1.0)

using namespace std;

static const double EPS = 1e-9;
typedef pair<int, int> pii;
typedef long long ll;

double l[11]={0}, v1, v2;

int solve(){
	
	double r = v1/(v1+v2);
	double x = r*l[10];
	
	for(int i=1; i <= 10; ++i){
		if( x <= l[i] )
			return i;
	}
	
	return 10;
}
	

int main(){
	
	char c;
	
	while(cin>>l[1]>>c>>l[2]>>c>>l[3]>>c>>l[4]>>c>>l[5]>>c>>
			l[6]>>c>>l[7]>>c>>l[8]>>c>>l[9]>>c>>l[10]>>c>>v1>>c>>v2, !cin.eof()){
		
		for(int i=1; i<=10; ++i){
		
			l[i]+=l[i-1];
		}
		
		cout << solve() << endl;
	}
		
	return 0;
}