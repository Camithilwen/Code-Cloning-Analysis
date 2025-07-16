#include <iostream>
#include <string>
using namespace std;
long long solve(long long x){
    if(x <= 6){
        return 1;
    }
    if(x <= 11){
        return 2;
    }
    long long res;
    res = x % 11;
    if(res == 0){
        return x / 11 * 2;
    }
    if(res <= 6){
        return x / 11 * 2 + 1;
    }
    else{
        return x / 11 * 2 + 2;
    }
}
int main(void){
    long long x;
    cin >> x;
    long long ans = solve(x);
    cout << ans << endl;
    
}
