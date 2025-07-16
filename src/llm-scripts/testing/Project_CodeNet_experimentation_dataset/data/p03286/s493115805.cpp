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
    int N; cin >> N;
    if(N == 0) {cout << 0 << endl; return 0;}
    int cnt = 0;
    string A;
    while(N != 0) {
        if(cnt % 2 == 0) {
            if(abs(N) % 2 == 1) {
                N -= 1;
                A = "1" + A;
            } else {
                A = "0" + A;
            }
        } else {
            if(abs(N) % 2 == 1) {
                N += 1;
                A = "1" + A;
            } else {
                A = "0" + A;
            }
        }
        N /= 2;
        //N *= -1;
        cnt++;
    }
    cout << A << endl;

    return 0;
}

