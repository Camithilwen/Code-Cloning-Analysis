#include <cstdio>
#include <iostream>
#include <algorithm>

#define MAX_STATIONS 100+1
#define INF 1<<15

#define reep(i,n,m) for(int i=n;i<m;i++)
#define rep(i,n) reep(i,0,n)



using namespace std;

class Stations{
private:
    int time[MAX_STATIONS][MAX_STATIONS];
    int cost[MAX_STATIONS][MAX_STATIONS];
public:
    void solve(int a[MAX_STATIONS][MAX_STATIONS], int r){
        //wayは文系をあらわす
        rep(way,MAX_STATIONS){
            rep(to,MAX_STATIONS){
                rep(from,MAX_STATIONS){
                    a[from][to] = min(a[from][to], a[from][way] + a[way][to]);
                    a[to][from] = a[from][to];
                }
            }
        }
        if(r==1){
            rep(i,MAX_STATIONS){
                rep(k,MAX_STATIONS){
                    time[k][i] = a[k][i];
                }
            }
        }
        else{
            rep(i,MAX_STATIONS){
                rep(k,MAX_STATIONS){
                    cost[k][i] = a[k][i];
                }
            }
        }
    }

    int getTime(int from, int to){
        return time[from][to];
    }

    int getCost(int from, int to){
        return cost[from][to];
    }
};

int main(void){
    int n,m;
    int t[MAX_STATIONS][MAX_STATIONS], c[MAX_STATIONS][MAX_STATIONS];
    while(cin >> n >> m,n+m){
        rep(i,MAX_STATIONS){
            rep(k,MAX_STATIONS){
                t[i][k] = INF;
                c[i][k] = INF;
            }
        }

        rep(i,n){
            int from,to,cost,time;
            cin >> from >> to >> cost >> time;
            t[from][to] = t[to][from] = time;
            c[from][to] = c[to][from] = cost;
        }

        Stations station;
        station.solve(c,0);
        station.solve(t,1);

        int q;
        cin >> q;

        rep(i,q){
            int from,to,r;
            cin >> from >> to >> r;
            if(r==1){
                cout << station.getTime(from,to) << endl;
            }else{
                cout << station.getCost(from,to) << endl;
            }
        }
    }
    return 0;
}