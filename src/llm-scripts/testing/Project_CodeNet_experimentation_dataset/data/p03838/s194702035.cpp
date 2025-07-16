#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, y;
    cin >> x >> y;

    long long int ans = 0;
    if(x == y) ans = 0;
    else if(x == 0){
        ans = abs(y);
        if(y < 0) ans += 1;
    }
    else if(y == 0){
        ans = abs(x);
        if(x > 0) ans += 1;
    }
    // different sign
    else if(x == -y) ans = 1;
    else if(x > 0 && y < 0) ans = 1 + abs(x-(-y));
    else if(x < 0 && y > 0) ans = min(y-x, 1+abs(y-(-x)));
    // same sign
    else if(x > y) ans = 2 + (x-y);
    else if(x < y) ans = y-x;
    
    cout << ans << endl;
    return 0;
}