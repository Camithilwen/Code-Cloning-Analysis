#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int l1 = 1, r1 = 2 + ((m - 1)/2) * 2; 
    int l2 = r1 + 1, r2 = l2 + 2 + ((m - 2)/2) * 2;
    //cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
    while(l1 < r1 && m > 0) {
        cout << l1 << " " << r1 << endl;
        l1++; r1--;
        m--;
    }
    while(l2 < r2 && m > 0) {
        cout << l2 << " " << r2 << endl;
        l2++; r2--;
        m--;
    }

    return 0;
}
// 1 2 3 4 5
// . .
//     .   .

// 1 2 3 4 5 6 7 8
// .     . .   .
//   . .