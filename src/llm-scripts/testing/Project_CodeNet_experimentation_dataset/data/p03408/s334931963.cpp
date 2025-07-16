#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <string.h>
#include <stack>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
int main() {
    int n,m;
    cin >> n;
    map<string, int>blue;
    map<string, int>red;
    rep(i, 0, n){
        string in;
        cin >> in;
        blue[in]++;
    }
    cin>>m;
    rep(i, 0, m){
        string in;
        cin >> in;
        red[in]++;
    }
    int ans = 0;
    for(auto i: blue){
        int blucnt =i.second;
        if(red[i.first] != 0){
            blucnt-=red[i.first];
        }
        ans = max(ans, blucnt);
    }
    cout << ans << endl;
    return 0;
}
