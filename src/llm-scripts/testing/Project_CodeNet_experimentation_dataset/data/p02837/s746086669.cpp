#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iomanip>

typedef long long ll;
const ll MOD = 1e9 + 7;
const long long INF = 1LL<<60;
const double PI=3.14159265358979323846;
const int NMAX=100005;
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<vector<pair<int,int>>> a(n);
    for(int i = 0; i < n; i++){
        int an;
        cin >> an;
        for(int j = 0; j < an; j++){
            int x,y;
            cin >> x >> y;
            x--;
            a[i].push_back({x,y});
        }
    }

    int ans = 0;
    for(int i = 0; i < (2<<n); i++){
        vector<bool> honest(n,false);
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if((i>>j) & 1){
                honest[j] = true;
                cnt++;
            }
        }

        for(int j = 0; j < n; j++){
            if(honest[j] == false) continue;
            for(int k = 0; k < a[j].size(); k++){
                int x = a[j][k].first;
                int y = a[j][k].second;
                if((honest[x] == false && y == 1) ||
                    (honest[x] == true && y == 0)){
                        cnt = -1;
                        break;
                    }
            }
            if(cnt == -1) break;
        }
        ans = max(ans, cnt);
    }

    cout << ans << endl;


    return 0;
}