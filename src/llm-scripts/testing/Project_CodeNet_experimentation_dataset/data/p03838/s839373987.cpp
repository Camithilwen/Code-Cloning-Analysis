#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define PI acos(-1)

int main(){
    long long x,y,d,ans;
    bool minus_x = false,minus_y = false;
    cin >> x >> y;
    if(x < 0)minus_x = true;
    if(y < 0)minus_y = true;

    d = abs(abs(x) - abs(y));
    if(x == 0 || y == 0){
        if(x == 0 && y < 0 || y == 0 && x > 0)ans = d + 1;
        else ans = d;

    }else{
        if(abs(x) > abs(y)){
        if(minus_x && minus_y)ans = d;
        else if(minus_x || minus_y)ans = d + 1;
        else ans = d + 2;
    }
    else if(abs(x) == abs(y)){
        if(minus_x && minus_y)ans = d;
        else if(minus_x || minus_y)ans = d + 1;
        else ans = d;
    }
    else{
        if(minus_x && minus_y)ans = d + 2;
        else if(minus_x || minus_y)ans = d + 1;
        else ans = d;
        }
    }
    cout << ans << endl;
}
