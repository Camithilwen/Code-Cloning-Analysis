#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<utility>
#include<numeric>
#include<algorithm>
#include<bitset>
#include<complex>

using namespace std;

typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

int main() {
	int l[10],v1,v2;
	for(;~scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",l,l+1,l+2,l+3,l+4,l+5,l+6,l+7,l+8,l+9,&v1,&v2);){
		int sum=0;
		int i;
		for(i=0;i<10;i++){
			sum+=l[i];
			//cout<<l[i]<<endl;
		}
		int len=0;
		for(i=0;i<10;i++){
			len+=l[i];
			if(len*v2>=(sum-len)*v1){
				cout<<i+1<<endl;
				break;
			}
		}
	}
	return 0;
}