#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	ll happiness = 0;
	while(n >= 500){
		happiness += 1000;
		n -= 500;
	}
	while(n >= 5){
		happiness += 5;
		n -= 5;
	}
	cout << happiness << endl;
}


