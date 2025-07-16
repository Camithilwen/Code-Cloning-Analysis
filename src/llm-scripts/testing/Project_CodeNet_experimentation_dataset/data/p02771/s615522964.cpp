#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int a[5];
    for(int i = 0; i < 3; i++) cin >> a[i];
    sort(a, a + 3);
    if(a[0] == a[2]) return cout << "No", 0;
    for(int i = 1; i < 3; i++) if(a[i] == a[i - 1]) return cout << "Yes", 0;
    cout << "No";

    return 0;
}
