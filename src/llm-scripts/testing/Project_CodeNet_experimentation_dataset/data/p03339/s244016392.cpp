#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    int n;
    string s;
    cin >> n >> s;
    vector<int> left(n,0),right(n,0);

    left[0] = 0;
    if(s[0] == 'W')left[0]++;
    reps(i,1,n){
        left[i] = left[i-1];
        if(s[i] == 'W')left[i]++;
    }

    right[n-1] = 0;
    if(s[n-1] == 'E')right[n-1]++;
    for(int j = n-2;j >= 0; j--){
        right[j] = right[j+1];
        if(s[j] == 'E') right[j]++;
    }

    // rep(i,n) cout << left[i] << endl;
    // cout << endl;
    // rep(i,n) cout << right[i] << endl;
    // cout << endl;

    int ans = right[1];
    ans = min(ans,left[n-1]);

    rep(i,n-1){
        ans = min(ans,right[i+2] + left[i]);
    }
    cout << ans << endl;

    return 0;
}