#include <bits/stdc++.h>
using namespace std;

int main(){
    int h1, h2, m1, m2 , k; cin >> h1 >> m1 >> h2 >> m2 >> k;
    m1 += 60 *  h1; m2 += h2 * 60;
    cout << m2 - m1 - k << '\n';
    return 0;
}