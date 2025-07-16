#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
//#define INF 2e9
#define ALL(v) v.begin(), v.end()
 
using namespace std;
typedef long long ll;

int main(){
    string W;
    cin >> W;
    int result=0;
    if(W[0]=='R'){
        result=1;
        if(W[1]=='R'){
            result=2;
            if(W[2]=='R'){
                result=3;
            }
        }
    }
    if(W[1]=='R'){
        if(result<1) result=1;
        if(W[2]=='R'){
            if(result<2) result=2;
        }
    }
    if(W[2]=='R'){
        if(result<1) result=1;
    }
    cout << result << endl;
    return 0;
}