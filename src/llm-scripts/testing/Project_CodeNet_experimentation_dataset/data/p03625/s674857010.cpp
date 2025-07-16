#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    map<ll, ll> a;

    for(int i = 0; i < N; i++) {
        ll A;
        cin >> A;
        a[A]++;
    }

    vector<ll> x;

    for(auto i = begin(a); i != a.end(); i++) {
        for(int j = i -> second; j > 1; j -= 2) {
            x.push_back(i -> first);
        }
    }

    sort(x.begin(), x.end(), greater<ll>());

    if(x.size() < 2) cout << 0 << endl;
    else cout << x[0] * x[1] << endl;
}