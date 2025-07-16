#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define Opy ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

typedef long long ll;

int main()
{
    //Opy;

/*-------------------------------------------------
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
-------------------------------------------------*/
    ll a, h = 0;

    cin>> a;

    h += (a - (a % 500)) * 2;

    a %= 500;

    h += a - (a % 5);

    cout<< h<< endl;

    return 0;
}

