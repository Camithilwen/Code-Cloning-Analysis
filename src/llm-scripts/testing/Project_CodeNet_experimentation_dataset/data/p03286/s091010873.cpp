#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
#include <iomanip>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	int n;
	cin >> n;
	
	string s="";
	while(n!=0){
		if(n%-2==1){
			s = '1'+s;
			n /= -2;
		}else if(n%-2==-1){
			s = '1'+s;
			n /= -2;
			n += 1;
		}else{
			s = '0'+s;
			n /= -2;
		}
	}
	
	if(s.size()==0) s = "0";
	cout << s << endl;
	
	
	return 0;
}