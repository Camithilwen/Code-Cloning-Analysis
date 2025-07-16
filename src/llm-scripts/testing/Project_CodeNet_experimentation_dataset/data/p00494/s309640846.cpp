#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <set>
#include <queue>
#include <map>
#include <iomanip>
#include <cstring>
#include <cmath>

using namespace std;
const long double eps = 1e-12;

typedef long long ll;
typedef pair<int , int> pt;

#define sz(a) ((int) a.size() )
#define LL(x) (x << 1)
#define RR(x) ((x << 1) | 1)
#define For(i , a , b) for (int i = a ; i <= b ; i++)
#define Ford(i , a , b) for (int i = a ; i >= b ; i--)
#define Rep(i , n) for (int i = 0 ; i < n ; i++)

const int maxn = 1000000 + 1912;
string s;
int lenJ[maxn] , lenI[maxn];

void ReadData() {
    cin >> s;
}

void Process() {
    lenJ[0] = s[0] == 'J';
    For(i , 1 , sz(s) - 1) if (s[i] == 'J') lenJ[i] = lenJ[i - 1] + (s[i] == 'J'); else lenJ[i] = 0;
    Ford(i , sz(s) - 1 , 0) if (s[i] == 'I') lenI[i] = lenI[i + 1] + (s[i] == 'I'); else lenI[i] = 0;
    int res = 0;
    int last = 0;
    Rep(i , sz(s)) if (s[i] == 'O') {
        last++;
        if (i - last >= 0 && lenJ[i - last] >= last && lenI[i + 1] >= last) res = max(res , last);
    } else last = 0;
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  //  freopen("/users/youaremysky/documents/workspace/input.inp" , "r" , stdin);
    ReadData();
    Process();
}