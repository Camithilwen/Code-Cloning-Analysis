#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<iomanip>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define sz(a) (int)a.size()
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long double n, m, d;
    cin >> n >> m >> d;
    if (d == 0) {
        cout << fixed<<setprecision(12)<<(m-1)*(1/n)  << endl;
    }
    else {
        cout << fixed<<setprecision(12)<<(m-1)*(2*(n-d)/(n*n)) << endl;
    }
}