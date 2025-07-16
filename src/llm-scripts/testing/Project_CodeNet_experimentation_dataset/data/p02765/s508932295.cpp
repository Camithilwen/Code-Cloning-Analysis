#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int N, R;
	cin >> N >> R;
	if(N>=10) {
		cout << R << endl;
		return 0;
	}
	else {
		cout << R + 100 * (10 - N) << endl;
		return 0;
	}
}










