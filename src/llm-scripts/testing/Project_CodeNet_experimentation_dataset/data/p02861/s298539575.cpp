#include"bits/stdc++.h"
using namespace std;
#define ll long long
#define mod 1000000007
#define prec(n) fixed<<setprecision(n)
int N;
int x[10], y[10];
 
double dist(int i, int j) {
    double dx = x[i] - x[j];
    double dy = y[i] - y[j];
    return pow(dx * dx + dy * dy, 0.5);
}
 
void solve() {
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> x[i] >> y[i];

    double dsum = 0.0;
	
	for (int i = 1 ;i<=N; ++i) {
		for (int j = i+1; j<=N;++j) {
			dsum += dist(i, j) * 2 / N;
		}
	}

	cout << prec(10) << dsum << "\n";

    return;
}
 
int main() {
    solve();
    return 0;
}