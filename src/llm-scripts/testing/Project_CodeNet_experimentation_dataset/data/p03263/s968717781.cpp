#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
int GCD(int a,int b){
    if(b == 0)return a;
    return GCD(b,a%b);
}
int main(void){
    int H,W;
    cin >> H >> W;
    int a[H][W];
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> a[i][j];
        }
    }
    int count = 0;
    vector<pair<int,int>> P;
    queue<int> que;
    for(int i=0;i<H;i++){
        if(i % 2 == 0){
            for(int j=0;j<W;j++){
                P.push_back(make_pair(i,j));
            }
        }
        else{
            for(int j=W-1;j>=0;j--){
                P.push_back(make_pair(i,j));
            }
        }
    }
    for(int i=0;i+1<P.size();i++){
        if(a[P[i].first][P[i].second] % 2 == 1){
            count ++;
            a[P[i+1].first][P[i+1].second]++;
            que.push(P[i].first);
            que.push(P[i].second);
            que.push(P[i+1].first);
            que.push(P[i+1].second);
        }
    }
    cout << count << endl;
    for(int i=0;i<count;i++){
        for(int j=0;j<4;j++){
            cout << que.front() + 1;
            que.pop();
            if(j != 3){
                cout << " " ;
            }
        }
        cout << endl;
    }
}
