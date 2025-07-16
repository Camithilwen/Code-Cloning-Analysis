#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
const int MOD = 1e9+7;
#define PI 3.14159265359
typedef long long ll;
using namespace std;


int main(){
	int n;
	string s;
	cin >> n >> s;
	vector<int> sumE(n+1), sumW(n+1);
	sumE[0] = 0, sumW[0] = 0;

	for (int i = 1; i <= n; i++){
		sumE[i] = sumE[i-1];
		sumW[i] = sumW[i-1];
		if (s[i-1] == 'E'){
			sumE[i] += 1;
		}else{
			sumW[i] += 1;
		}
	}
	int ans = MOD;
	for (int i = 1; i <= n; i++){
		int temp1 = sumW[i-1];
		int temp2 = sumE[n] - sumE[i];
		ans = min(ans, temp1 + temp2);
	}

	cout << ans << endl;
	return 0;
}
