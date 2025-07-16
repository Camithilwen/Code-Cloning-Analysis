#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int h, w, n;
    cin >> h >> w >> n;
    cout << (n + max(h, w)-1) / max(h, w) << endl;
    return 0;
}