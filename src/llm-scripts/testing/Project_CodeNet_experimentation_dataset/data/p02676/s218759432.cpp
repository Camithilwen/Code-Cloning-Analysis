#include<bits/stdc++.h>
using namespace std;

int main() {
    int k;
    string s;
    string kq;

    cin >> k;
    cin >> s;

    int dodai = s.length();

    if (k < 1 || k > 100)
        return 0;

    if (dodai < 1 || dodai > 100)
        return 0;

    for (int i = 0; i < k; ++i)
    {
        if (k > dodai)
        {
            cout << s;
            return 0;
        }
        if (s[i] >= 'a' && s[i] <= 'z')
            kq += s[i];
        else
            return 0;
    }

    if (k < dodai)
        kq += "...";

    cout << kq;

    return 0;
}