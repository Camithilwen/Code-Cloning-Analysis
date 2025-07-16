#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
long mod = (long) 1e9 + 7;

int main(){
    
    int n;
    long cnt = 0, r = 0, g = 0, b = 0;
    cin >> n;
    
    string s;
    cin >> s;
    
    vector<int> v(n,0);
    rep(i,n){
        if(s[i] == 'R'){
            v[i] = 0;
            r++;
        } else if(s[i] == 'G'){
            v[i] = 1;
            g++;
        } else if(s[i] == 'B'){
            v[i] = 2;
            b++;
        }
    }
    
    for(int i = 1; i < n - 1; i++){
        int a = min(i, n - 1 - i);
        
        for(int j = 1; j <= a; j++){
            if(v[i] != v[i-j] && v[i] != v[i+j] && v[i-j] != v[i+j]) cnt++;
        }
    }
    
    long ans = r * g * b - cnt;
    
    cout << ans << "\n";
    
    return 0;
}
