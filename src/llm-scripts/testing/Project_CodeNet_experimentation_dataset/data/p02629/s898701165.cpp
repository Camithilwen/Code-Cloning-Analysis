#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main()
{
    int64_t n;
    string s = "";

    cin >> n;

    while(n!=0)
    {
        n--;
        s += 'a' + n % 26;
        n /= 26;
    }

    reverse(s.begin(), s.end());

    cout << s << endl;

}