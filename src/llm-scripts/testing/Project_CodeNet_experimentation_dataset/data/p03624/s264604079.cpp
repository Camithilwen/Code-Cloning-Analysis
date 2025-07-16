#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    int a[26];
    for (int i = 0; i < 26; i++) a[i] = 0;
    bool occur = true;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        a[s[i] - 97]++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (a[i] == 0)
        {
            occur = false;
            cout << char(i + 97);
            break;
        }
    }
    if (occur == true) cout << "None";
}