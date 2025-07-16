//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/jsc2019-qual/tasks/jsc2019_qual_c
//左端、右端を選んで操作、という操作は
//まず左端のみに注目し、次に右端のみに注目していく
//また最左端にまとめるなんて考え方も
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (LL)(1e18)+1;
const int INF_INT = 2147483647-1e6;
const LL mod = 1000000007ll;

int N;
string S;

LL ans = 1;

void solve(){
	int cur = 0;
	for(int i=0;i<2*N;i++){
		if(S[i]=='B'){
			if(cur%2==1){
				ans = ans*cur%mod;
				cur--;
			}else{
				cur++;
			}
		}
		if(S[i]=='W'){
			if(cur%2==1){
				cur++;
			}else{
				ans = ans*cur%mod;
				cur--;
			}
		}
	}
	if(cur>0) ans = 0;
	for(int i=0;i<N;i++) ans = ans*(i+1)%mod;
}
 
int main(){
	cin >> N;
	cin >> S;
 
	solve();

	cout << ans << endl;
	return 0;
}