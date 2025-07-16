#include <bits/stdc++.h>
#define rep(i , n) for (int i = 0; i < (int)(n); i++)
const int INF = 1<<29;
using namespace std;
using ll = long long;
int n, sum, y, a[105];
double g, t = 1e9;
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	g = 1.0 * sum / n;
	for(int i = 0; i < n; i++) {
		if(abs(a[i] - g) < t){
			t = abs(a[i] - g);
			y = i;
		}
	}
	cout << y << endl;;
}