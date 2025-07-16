#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

ll k;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k;
    int n = 50;
    vector <ll> a(n);
    for(int i = 0 ; i < n ; i++){
        a[i] = i;
    }
    ll f = k / n;
    for(auto &i : a) i += f * n;
    for(auto &i : a) i -= f * (n - 1);
    for(int itt = 0 ; itt < k % n ; itt++){
        int mn = 0;
        for(int j = 0 ; j < n ; j++){
            if(a[j] < a[mn]) mn = j;
        }
        for(int j = 0 ; j < n ; j++){
            if(j == mn) a[j] += n;
            else a[j]--;
        }
    }
    cout << n << endl;
    for(auto &i : a) cout << i << " ";
    cout << endl;
}
