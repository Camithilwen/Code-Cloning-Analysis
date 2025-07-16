//g++ -std=c++14 test.cpp -o test.out

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
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N;
vector<tuple<LL,LL,LL>> dish;

LL ans = 0;

void solve(){
	sort(dish.begin(),dish.end());
	for(int i=0;i<N;i++){
		int j = N-1-i;
		//cout << get<1>(dish[j]) << " " << get<2>(dish[j])<< endl;
		if(i%2==0){
			ans += get<1>(dish[j]);
		}
		if(i%2==1){
			ans -= get<2>(dish[j]);
		}
	}
}
 
int main(){
    cin >> N;
    for(int i=0;i<N;i++){
    	LL a,b;cin >> a >> b;
    	dish.push_back(tuple<LL,LL,LL>(a+b,a,b));
    }
 
    solve();

    cout << ans << endl;
    return 0;
}