#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    if(n == 0){
        cout << 0 << endl; return 0;
    }
    string bin = "";
    while(n != 0){
        ll foo = n%((ll)-2);
        n /= ((ll)-2);
        if(foo < 0){
            foo += abs((ll)-2);
            n++;
        }
        bin = to_string(foo)+bin;
    }
    cout << bin << endl;
    return 0;
}
