#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int main() {
    int x , y;
    cin >> x >> y;
    int t = abs(abs(x)-abs(y));
    if((x > 0 && y < 0) || (x < 0 && y > 0)){
        t++;
    }
    else if((x == 0 || y == 0) && y < x){
        t++;
    }
    else if (y < x){
        t+=2;
    }
    cout << t << endl; 
    return 0;
}