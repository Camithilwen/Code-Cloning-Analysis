#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    int K, X;
    cin >> K >> X;
    for(int i=X-K+1; i<K+X; ++i){
        if(i==K+X-1){
            cout << i;
        }
        else cout << i << " ";
    }
    return 0;

}
