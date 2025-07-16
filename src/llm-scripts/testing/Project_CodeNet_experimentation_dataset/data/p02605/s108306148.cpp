#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <map>

using namespace std;
const int INF = 1e8;

//0:up, 1:right, 2:down, 3:left
vector<pair<int, int>> direction(4);

//距離を計算する
int f( vector<pair<int, int>> vec){
    sort(vec.begin(), vec.end());
    int dist = INF;
    for(int i=0; i<vec.size()-1; ++i){
        if(vec[i].second == 0 && vec[i+1].second != 0){
            int tmp = vec[i+1].first - vec[i].first; 
            dist = min(dist, tmp);
        }
    }
    return dist;
}

int main(){
    int N; cin >> N ;
    vector<int> x(N), y(N), dir(N);

    for(int i=0; i<N; ++i){
        int X, Y;
        char U;
        cin  >> x[i] >> y[i];
        cin  >> U;

        if( U == 'U') dir[i] = 0;
        if( U == 'R') dir[i] = 1;
        if( U == 'D') dir[i] = 2;
        if( U == 'L') dir[i] = 3;
    }

    int ans = INF;

    //四回分ですべてをカバー
    for(int i=0; i<4; ++i){
        
        //すべてのx座標を独立に考える
        // x座標: [{y座標1, 方向1}, {y座標2, 方向2}]　みたいな感じ 
        {
            map<int, vector<pair<int, int>>> mp;
            //180度パターン、上と下でぶつかる場合を考える
            for(int i=0; i<N; ++i){
                if (dir[i] != 0 && dir[i] !=2) continue;
                mp[x[i]].emplace_back( y[i], dir[i] );
            }

            for(auto y_dir : mp){
                int res = f(y_dir.second);
                if(res == INF)continue;
                ans = min(ans, res*5);
            }
        }
        //90度パターン、直角にぶつかる。ここではUとRでぶつかるを想定
        {
            map<int, vector<pair<int, int>>> mp;
            //この場合x+y座標の和が一致する
            for(int i=0; i<N; ++i){
                if (dir[i] != 0 && dir[i] !=1) continue;
                mp[ x[i] + y[i] ].emplace_back(y[i], dir[i]); 
            }
            for(auto y_dir : mp){
                int res = f(y_dir.second);
                if(res == INF)continue;
                ans = min(ans, res*10);
            }
        }

        //時計回りに回転
        for(int i=0; i<N; ++i){
            int px = y[i];
            int py = -x[i];
            x[i] = px;
            y[i] = py;
            dir[i] = (dir[i] + 1)%4;
        }
    }

    if(ans == INF){
        cout << "SAFE" << endl;
    }else{
        cout << ans << endl;
    }

}