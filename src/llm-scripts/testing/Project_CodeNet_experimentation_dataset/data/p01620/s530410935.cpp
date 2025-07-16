#include <iostream>
#include <map>
using namespace std;

string Alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
int l = 52;

int main(void) {
    int n, x, d;
    int k[1000];
    string s;
    map<char, int> mp;
    for (int i = 0; i < 52; i++) mp[Alpha[i]] = i;

    while (1) {
        cin >> n;
        if (n == 0) break;

        for (int i = 0; i < n; i++) cin >> k[i];
        cin >> s;

        for (int i = 0; i < s.size(); i++) {
            d = k[i % n];
            x = (mp[s[i]] + 52 - d) % l;
            cout << Alpha[x];
        }
        cout << endl;
    }

    return 0;
}