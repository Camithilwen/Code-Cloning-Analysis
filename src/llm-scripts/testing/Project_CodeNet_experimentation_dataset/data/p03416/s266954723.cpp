#include<iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include<map>	
#include<cstring>
#include<iomanip>
#include <string>
#include <vector>	
#include<unordered_map>
#include<unordered_set>
using namespace std;


typedef long long unsigned llu;
typedef long double ld;
#define ll long long
#define PI 3.14159265358979323846
#define For(i, a, b) for (int i = a, sz = (int)b; i < sz; i++)
#define rFor(i, a, b, c) for (int i = (a); i >= (b); i -= (c))
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define fill(a, b) memset(a, b, sizeof(a))
#define IO ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0)
const int mod = 1000000007;
const ll inf = 1000000000009;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b) { return a*b/gcd(a,b);}

//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdoutn

int main() {
    IO;
    int a, b, x, y, r, c, ans;
    cin >> a >> b;
    x = a / 1000, y = b / 1000, r = (a / 100) % 10, c = (b / 100) % 10;
    ans = (y - x - 1) * 10 + 10 - r + c + 1;
    if (a > (a / 100) * 100 + ((a / 1000) % 10) * 10 + (a / 10000))
        ans--;
    if (b < (b / 100) * 100 + ((b / 1000) % 10) * 10 + (b / 10000))
        ans--;
    printf("%d\n", ans);
   // system("pause");
    return 0;
}