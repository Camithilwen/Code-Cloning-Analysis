#include <bits/stdc++.h>          
using namespace std;             
typedef long long ll;  

int main() {
    ll N;
    cin >> N;
    vector<char> name = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
    'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    ll block = 0;
    vector<int> x;
    while (N>0) {
        N--;
        x.push_back(N%26);
        N /= 26;
    }

    string ans = "";

    for (ll i=x.size()-1; i>=0; i--) {
        ans += name[x[i]];
    }

    cout << ans << endl;
}