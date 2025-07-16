#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

// 距離でやると困る
int main(){
    int N;
    cin >> N;

    int a[N], b[N], c[N], d[N];
    for(int i=0; i<N; i++) cin >> a[i] >> b[i];
    for(int i=0; i<N; i++) cin >> c[i] >> d[i];

    P rl[N];
    for(int i=0; i<N; i++){
        rl[i] = P(c[i], d[i]);
    }

    sort(rl, rl+N);

    int cnt = 0;
    bool used[N];
    fill(used, used+N, false);
    for(int i=0; i<N; i++){
        int rx = rl[i].first;
        int ry = rl[i].second;
        int mx = -1;
        int ind = -1;
        for(int j=0; j<N; j++){
            if(used[j]) continue;
            if(i == j) continue;
            if(rx <= a[j] || ry <= b[j]) continue;
            if(mx < b[j]){
                mx = b[j];
                ind = j;
            }
        }
        if(ind != -1){
            cnt++;
            used[ind] = true;
            // cout << i << " " << ind << endl;
        }
    }

    cout << cnt << endl;

    return 0;
}