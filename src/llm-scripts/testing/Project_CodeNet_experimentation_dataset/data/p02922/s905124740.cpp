#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int a, b;
    cin >> a >> b;
    
    int sum = 1, cnt = 0;
    while(sum < b) {
        sum += a-1;
        cnt++;
    }
    
    cout << cnt << endl;
    
    
    return 0;
}
