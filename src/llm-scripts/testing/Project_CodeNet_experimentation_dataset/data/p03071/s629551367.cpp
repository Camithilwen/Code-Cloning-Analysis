#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define all(a) a.begin(), a.end()
#define All(a) a.rbegin(), a.rend()
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.precision(10), cout << fixed
//double Time=clock();
int main() {
    ios;
    int a, b;
    cin >> a >> b;
    cout << max({a + b, a + (a - 1), b + (b - 1)});
    //cout <<endl<< clock() - Time << endl;
    return 0;
}