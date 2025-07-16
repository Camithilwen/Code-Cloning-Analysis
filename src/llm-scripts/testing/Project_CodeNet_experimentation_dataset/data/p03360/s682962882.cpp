#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a,b,c,k;
    int64_t target;
    int64_t remains;
    cin >> a >> b >> c >> k;
    target = max(a,max(b,c)); 
    remains = a + b + c - target;
    target = target * pow(2,k);
    cout << target + remains << endl;
    return 0;
}
