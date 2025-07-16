#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
        ll N; cin >> N;
        vector<ll> A(N, 0);
        map<ll, ll, greater<ll>> m;
        for (int i = 0; i < N; ++i) {
                cin >> A[i];
                m[A[i]]++;
        }
        int cnt = 0;
        ll a = 0;
        ll b = 0;
        for (auto i : m) {
                if (i.second > 1) {
                        if (cnt == 0) {
                                a = i.first;
                                if (i.second > 3) {
                                        b = i.first;
                                        break;
                                }
                                cnt++;
                        }
                        else {
                                b = i.first;
                                break;
                        }
                }
        }
        cout << a * b << endl;



}
