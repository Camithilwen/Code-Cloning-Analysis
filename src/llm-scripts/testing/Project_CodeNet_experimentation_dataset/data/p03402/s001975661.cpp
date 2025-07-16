#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = s; i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << endl;
#define CFYN(n) cout << ( (n) ? "YES":"NO") << endl;
#define OUT(n) cout << (n) << endl;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;

int main(void)
{
    IOS
    const int HW = 100;
    const char W = '.';
    const char B = '#';
    int a, b;
    cin >> a >> b;
    vector<string> ss;
    REP(i,HW) {
        if (i < HW /2) ss.emplace_back(string(HW,B));
        else ss.emplace_back(string(HW,W));
    }

    int x = 0, y = 0;
    int i = a-1;
    while(i > 0) {
        ss[y][x] = W;
        x += 2;
        if (x >= HW) {
            y += 2;
            x = 0;
        }
        i--;
    }

    x = 0, y = HW-1;
    i = b-1;
    while(i > 0) {
        ss[y][x] = B;
        x += 2;
        if (x >= HW) {
            y -= 2;
            x = 0;
        }
        i--;
    }

    cout << HW << " " << HW << '\n';
    REP(i,HW) cout << ss[i] << '\n';

    return 0;
}