////////////////////////////////////////////
///                                      ///
///         Template ver. 1 rapel        ///
/// Fear is Temporary, Regret is Forever ///
///          Must Try and Get AC         ///
///                                      ///
////////////////////////////////////////////
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>

#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <utility>

#include <math.h>
#include <complex>

#include <assert.h>
#include <time.h>
//#include <chrono>
//#include <random>

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <bitset>

#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define endl '\n'
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

void desperate_optimization(int precision){
  	ios_base::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
  	cout.setf(ios::fixed);
  	cout.setf(ios::showpoint);
  	cout.precision(precision);
}

const int N = 1e5;
int arr[N + 5];
vector<int> lst[N + 5];
int tot = 0;
int depth[N + 5];
int n, k;

void dfs(int idx) {
	depth[idx] = 0;
	for(auto x: lst[idx]) {
		dfs(x);
		depth[idx] = max(depth[idx], depth[x] + 1);
	}
//	cout<<"IDX "<<idx<<" "<<depth[idx]<<endl;
	if(depth[idx] == k - 1 && arr[idx] != 1 && idx != 1) {
		depth[idx] = -1;
		tot++;
	}
}

void hora(int tc) {
	cin>>n>>k;
	for(int i = 1;i <= n;i++) {
		cin>>arr[i];
		if(i != 1) lst[arr[i]].PB(i);
	}
	if(arr[1] != 1) tot++;
	dfs(1);
	cout<<tot<<endl;
}

int main(){
	desperate_optimization(10);
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}


