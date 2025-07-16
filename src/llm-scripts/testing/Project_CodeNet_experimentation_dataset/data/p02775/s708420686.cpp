//#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 1000000007

using namespace std;
using ll = long long;
using ldb = long double;

int main() {
    string N;   cin >> N;
    int L = N.size();
    reverse(N.begin(), N.end());
    vector<int> a(L + 2);
    for (int i = 0; i < L; i++) {
        a[i] = N[i] - '0';
        //printf("a[%d]=%d ", i, a[i]);
    }

    vector<int> dp(L + 1);
    for (int i = 0; i <= L; i++) {
        if (a[i] < 5) dp[i] = a[i];
        else if (a[i] == 5) {
            dp[i] = 5;
            if (a[i + 1] >= 5) a[i + 1]++;           
        }
        else {
            dp[i] = 10 - a[i];
            a[i + 1]++;
            //a[i + 1] %= 10;
        }
    }
    /*
    cout << endl << 0;
    for (int i = L - 1; i >= 0; i--) {
        cout << N[i];
    }
    cout << endl;
    */
    ll ans = 0;
    for (int i = L; i >= 0; i--) {
        //cout << dp[i];
        ans += dp[i];
    }

    //cout << endl;
    cout << ans << endl;
}
