#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define Sort(Array) sort(Array.begin(), Array.end())
#define Reverse(a) reverse(a.begin(), a.end())
#define out(ans) cout << ans << endl;
const int MOD = 1000000007;
const int INF = 2147483647;
const ld PI = 3.14159265358979323846;

//------------↓------------- M -------------- E ---------------- M --------------- O ---------------↓--------------//
// コンパイル 
// g++ -std=c++1z
//
// -------型変換--------
// int を string に変換
// string s = to_string(n);
// string を int に変換
// int n = stoi(s);
//
// -------二分探索---------
// k以上の値が最初に現れる時のイテレータ
// lower_bound(data.begin(), data.end(), k)
// kより大きい値が最初の現れる時のイテレータ O(logN)
// upper_bound(data.begin(), data.end(), k)
// kがdataに存在するかをtrue or falseで返す O(logN)
// binary_search(data.begin(), data.end(), k)
// 
//
//
//
//
//
// 
//------------↑------------- M -------------- E ---------------- M --------------- O ---------------↑--------------//




int main() {

    int N; cin >> N;
    int a[N+1];
    for (int i = 1; i <= N; ++i) cin >> a[i];

    int b[N+1]; rep(i,N+1) b[i] = -1;
    vector<int> ans;
    for (int i = N; i >= 1; --i) {
        int j = 2;
        int sum = 0;
        while (i*j <= N) {
            sum += b[i*j];
            ++j;
        }
        b[i] = (a[i] + sum) % 2;
        if (b[i] == 1) ans.push_back(i);
    }


    cout << ans.size() << endl;
    rep(i,ans.size()) cout << ans[i] << " ";
    cout << endl;

    return 0;
}



