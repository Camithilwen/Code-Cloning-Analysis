//by rng_59
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;

#define REP(i,n) for(int (i)=0; i<(int)(n); i++)

bool col[1000010];
bool row[1000010];
const int mod = 1e9+7;
int main(){
	int N,M;
	long long ans = 1;
	cin >> N >> M;
	REP(i,N) {
		int a;
		cin >> a;
		if(row[a]) {
			cout << 0;
			return 0;
		}
		row[a] = 1;
	}
	REP(i,M) {
		int b;
		cin >> b;	
		if(col[b]) {
			cout << 0;
			return 0;
		}
		col[b] = 1;
	}
	int c=0,r=0;
	for(int i=N*M; i>0; i--) {
        int tc = c,tr = r;
        if(col[i]) {
			tc = 1;
			c++;
		}
        if(row[i])  {
			tr = 1;
			r++;
		}
        if(col[i] || row[i]) ans *= (tc*tr)%mod;
        else ans *= (tc*tr-(N*M-i))%mod;
		ans %= mod;
    }
	cout << ans%mod << endl;
	return 0;
}

