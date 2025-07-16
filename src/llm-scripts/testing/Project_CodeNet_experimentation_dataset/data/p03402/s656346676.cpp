/**
 *    This code has been written by YueGuang, feel free to ask me question. Blog: http://www.yx.telstudy.xyz
 *    created:
 */
#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#define REP(i, a, b) for(int i = a; i < b; i++)
#define REP_(i, a, b) for(int i = a; i <= b; i++)
#define sl(n) scanf("%lld", &n);
#define si(n) scanf("%d", &n);
#define RepAll(a) for(auto x: a)
#define cout(ans) cout << ans << endl;
typedef long long ll;
using namespace std;
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    cout<<"100 100\n";
    REP(i, 0, 100)
    {
        REP(j, 0, 100)
            i < 50 ? cout<< ( i%2 == 1 && j%2 == 1&& (--a) > 0 ? "." : "#" ) : cout << (i%2 == 1 && j%2 == 1&& (--b) > 0 ? "#" : ".");
        cout << '\n';
    }
}
