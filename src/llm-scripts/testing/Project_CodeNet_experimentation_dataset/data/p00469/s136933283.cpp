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

int cards[10];
set<int> nums;
int n;

void f(int m,int k,int used){
	if(k==0){
		nums.insert(m);
		return;
	}
	int i;
	for(i=0;i<n;i++){
		if(used&1<<i)continue;
		f(m*(cards[i]<10?10:100)+cards[i],k-1,used|1<<i);
	}
}

int main() {
	int k;
	while(n=in(),k=in()){
		nums.clear();
		int i;
		for(i=0;i<n;i++){
			cards[i]=in();
		}
		f(0,k,0);
		cout<<nums.size()<<endl;
	}
	return 0;
}