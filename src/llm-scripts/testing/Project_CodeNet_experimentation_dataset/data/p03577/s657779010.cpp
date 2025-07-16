#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S, target = "FESTIVAL";
    cin >> S;

    S.replace(S.length()-target.length(),S.length(),"");

    cout << S << endl;

    return 0;
}