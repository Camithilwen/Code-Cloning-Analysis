#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

class Graph {
public:
    int N;
    vector<vector<int>> G;
    vector<bool> visit;
    vector<int> cir;
    vector<int> exist;

    Graph(int N) : N(N) {
        G.resize(N);
        visit.resize(N, false);
        exist.resize(N, -1);
    }

    void add_edge(int s, int t){
        G[s].push_back(t);
    }

    bool dfs(int n, int s){
        if(n == s && visit[n]){
            return true;
        }
        if(visit[n]){
            return false;
        }


        visit[n] = true;
        for(int i = 0; i < (int)G[n].size(); i++){
            int nx = G[n][i];
            if(dfs(nx, s)){
                cir.push_back(n);
                return true;
            }
        }

        return false;
    }

    void solve(){
        //0 ~ N-1について自身に戻れるかdfsをN回
        bool found = false; //閉路があるか

        for(int i = 0; i < N; i++){
            fill(visit.begin(), visit.end(), false);
            if(dfs(i, i)){
                found = true;
                break;
            }
        }

        if(!found){
            cout << -1 << endl;
            return;
        }

        reverse(cir.begin(), cir.end());

        while(true){
            //debug
            /*
            cout << "cir = ";
            for(int val : cir){
                cout << val + 1 << " ";
            }
            cout << endl;
            */

            //閉路上の点かどうかを示すexist更新
            fill(exist.begin(), exist.end(), -1);
            for(int i = 0; i < (int)cir.size(); i++){
                exist[cir[i]] = i;
            }

            cir.push_back(cir[0]);

            bool check = false;
            for(int i = 0; i < (int)cir.size() - 1; i++){
                int n = cir[i];
                for(int j = 0; j < (int)G[n].size(); j++){
                    int nx = G[n][j];
                    if(exist[nx] >= 0 && nx != cir[i + 1]){
                        //閉路作り直し
                        check = true;

                        vector<int> tmp;
                        if(exist[n] < exist[nx]){
                            for(int k = 0; k < (int)cir.size() - 1; k++){
                                if(k <= exist[n] || exist[nx] <= k) tmp.push_back(cir[k]);
                            }
                        } else {
                            //cout << "hoge" << endl;
                            for(int k = exist[nx]; k <= exist[n]; k++){
                                tmp.push_back(cir[k]);
                            }
                        }

                        cir = tmp;
                        break;
                    }
                }

                if(check) break;
            }

            if(!check) break;
        }

        cout << cir.size() - 1 << endl;
        for(int i = 0; i < (int)cir.size() - 1; i++){
            cout << cir[i] + 1 << endl;
        }

        return;
    }
};

int main(){
    int N, M;
    cin >> N >> M;

    Graph gr = Graph(N);

    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        gr.add_edge(a - 1, b - 1);
    }

    gr.solve();
    return 0;
}