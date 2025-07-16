#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a(2);
    int k;
    cin >> a[0] >> a[1] >> k;

    int times = 0;
    int side = 0;
    while(1){
        if(a[side] % 2 == 1) a[side] -= 1;
        a[side] /= 2;
        a[(side+1)%2] += a[side];
        side += 1;
        side %= 2;
        times += 1;
        if(times == k) break;
    }

    cout << a[0] << " " << a[1] << endl;
    return 0;
}