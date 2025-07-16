#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    string ans = "Yes";
    for(int i=0; i<s.size(); i++)
    {
        if(i%2==0 && s.at(i) != 'h') ans = "No";
        else if(i%2==1 && s.at(i) != 'i') ans = "No";
    }
    if(s.length()%2==1) ans = "No";
    cout << ans << '\n';

    return 0;
}
