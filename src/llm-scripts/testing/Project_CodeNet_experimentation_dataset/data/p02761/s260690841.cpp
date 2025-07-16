#pragma warning(disable: 4996)
#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <math.h>
#include <algorithm>

using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
    int n, m;
    cin >> n >> m;
    vector<int>s(m);
    vector<int>c(m);
    vector<int>cnt(3),cnt2(3);
    rep(i, 3)cnt[i] = -101,cnt2[i] = 0;
    int ans = 0;
    
    rep(i, m) {
        cin >> s[i] >> c[i];
        if (n == 1) {
            if (s[i] > 1) {
                cout << -1 << endl;
                return 0;
            }
            else {
                if (cnt[0] !=  c[i] && cnt2[0] != 0) {
                    cout << -1 << endl;
                    return 0;
                }
                if (cnt2[0] == 0) {
                    ans += c[i];
                }
                cnt2[0]++;
                cnt[0] = c[i];
            }
        }
        else if (n == 2) {
            if (s[i] > 2) {
                cout << -1 << endl;
                return 0;
            }
            else {
                if (s[i] == 2) {
                    if (cnt[1] != c[i] && cnt2[1] != 0) {
                        cout << -1 << endl;
                        return 0;
                    }
                    if (cnt2[1] == 0) {
                        ans += c[i];
                    }
                    cnt2[1]++;
                    cnt[1] = c[i];
                }
                else if (s[i] == 1) {
                    if (cnt[0] != c[i] && cnt2[0] != 0) {
                        cout << -1 << endl;
                        return 0;
                    }
                    if (c[i] == 0) {
                        cout << -1 << endl;
                        return 0;
                    }
                    if (cnt2[0] == 0) {
                        ans += c[i] * 10;
                    }
                    cnt2[0]++;
                    cnt[0] = c[i];
                }
            }
        }
        else {
            if (s[i] == 3) {
                if (cnt[2] != c[i] && cnt2[2] != 0) {
                    cout << -1 << endl;
                    return 0;
                }
                if (cnt2[2] == 0) {
                    ans += c[i];
                }
                cnt2[2]++;
                cnt[2] = c[i];
            }
            if (s[i] == 2) {
                if (cnt[1] != c[i] && cnt2[1] != 0) {
                    cout << -1 << endl;
                    return 0;
                }
                if (cnt2[1] == 0) {
                    ans += c[i] * 10;
                }
                cnt2[1]++;
                cnt[1] = c[i];
            }
            else if (s[i] == 1) {
                if (cnt[0] != c[i] && cnt2[0] != 0) {
                    cout << -1 << endl;
                    return 0;
                }
                if (c[i] == 0) {
                    cout << -1 << endl;
                    return 0;
                }
                if (cnt2[0] == 0) {
                    ans += c[i] * 100;
                }
                cnt2[0]++;
                cnt[0] = c[i];
            }
        }
        
    }
    if (n == 2 && cnt2[0] == 0)ans = ans + 10;
    if (n == 3 && cnt2[0] == 0)ans = ans + 100;
    cout << ans << endl;
    return 0;
}