#include <bits/stdc++.h>
#include<math.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18 


int main () {
    int k, x ;
    cin >> k >> x ;
    int t = x + (k - 1) ;
    int p = x - (k - 1) ;
    for(int i = p; i <= t ; i++){
        cout << i <<  " " ;
    }
    cout << endl ;
} 