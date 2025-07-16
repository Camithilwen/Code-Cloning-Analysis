/*      ░░█ ▄▀█ █   █▀ █░█ █▀█ █▀▀ █▀▀   █▀█ ▄▀█ █▀▄▀█
        █▄█ █▀█ █   ▄█ █▀█ █▀▄ ██▄ ██▄   █▀▄ █▀█ █░▀░█     */

// Author : Udit "luctivud" Gupta @ (https://www.linkedin.com/in/udit-gupta-1b7863135/)


#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

typedef long long int lld;
typedef unsigned long long int llu;


#define       TESTCASES()  cin >> (T3X0); T353 = T3X0; while(T3X0--)
#define       _input(V3C)  for(auto &V3C_I7 : (V3C)) cin >> (V3C_I7)
#define mems(A77AY, V4LU)  memset((A77AY), (V4LU), sizeof((A77AY)))
#define  CH3K(I7, E4, S7)  (((S7)<0) ? (I7)>(E4) : (I7)<(E4))
#define for4(I7,S4,E4,S7)  for(auto I7=(S4); CH3K(I7,E4,S7); (I7)+=(S7))




void solveEachTest(lld T35TC453N = 1) {
    int ans = 0;
    int n ; cin >> n;
    string a, b, c;
    cin >> a >> b >> c;
    for (int i = 0; i < n; i++) {
        set <char> se;
        se.insert(a[i]);
        se.insert(b[i]);
        se.insert(c[i]);
        ans += (se.size() - 1);
    }
    cout << ans;
    cout << "\n";

    return;
}


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    lld T3X0 = 0, T353 = 1;

    // TESTCASES()
    solveEachTest(T353 - T3X0);
    return 0;
}
