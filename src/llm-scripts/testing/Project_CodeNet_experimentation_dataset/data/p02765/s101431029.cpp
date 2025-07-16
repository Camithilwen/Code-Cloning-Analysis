#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,r;
    cin >> n >> r;
    if(n<10) cout << r+(10-n)*100 << "\n";
    else cout << r << "\n";

    return 0;
}