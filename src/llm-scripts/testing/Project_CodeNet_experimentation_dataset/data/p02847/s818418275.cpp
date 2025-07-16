#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;




int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    string x;
    cin >> x;
    int ans = 0;
    for(int i = 0; i < 7; i++) if(s[i] == x) ans = i;
    cout << 7 - ans;

    return 0;
}
