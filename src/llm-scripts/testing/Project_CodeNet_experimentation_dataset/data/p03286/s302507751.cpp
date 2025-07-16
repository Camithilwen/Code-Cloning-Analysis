#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string res = "";
    while(n != 0)
    {
        if(n % 2 == 0) res = "0" + res;
        else
        {
            res = "1" + res;
            n--;
        }
        n /= -2;
    }
    if(res == "") res = "0";
    cout << res << endl;
}