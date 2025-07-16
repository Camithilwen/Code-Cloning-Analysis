#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
#include <cstring>
#include <deque>
#include <iomanip>
#include <limits>
#include <fstream>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
typedef pair<int, int> P;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,d1,d2;
  cin>>n>>d1>>d2;
  vector<int> SQRT(4*n*n+1,-1);
  for(int i=0;i<=2*n;i++){
    SQRT[i*i]=i;
  }
  vector<vector<int> > alive(2*n, vector<int>(2*n, 1));
  for(int rot=0;rot<2;rot++){
    int d=(rot==0?d1:d2);
    vector<vector<int> > was(2*n, vector<int>(2*n, 0));
    for(int i=0;i<2*n;i++){
      for(int j=0;j<2*n;j++){
        if(was[i][j]||!alive[i][j])continue;
        vector<P> que(1, P(i,j));
        was[i][j]=1;
        for(int b=0;b<(int)que.size();b++){
          int x=que[b].first;
          int y=que[b].second;
          for(int xx=0;xx<2*n;xx++){
            int dy=d-(x-xx)*(x-xx);
            if(dy>=0&&dy<=4*n*n&&SQRT[dy]!=-1){
              dy=SQRT[dy];
              int yy=y-dy;
              if(yy>=0&&yy<2*n&&was[xx][yy]==0&&alive[xx][yy]){
                que.emplace_back(xx, yy);
                was[xx][yy]=3-was[x][y];
              }
              if(dy != 0){
                yy = y + dy;
                if(yy>=0&&yy<2*n&&was[xx][yy]==0&&alive[xx][yy]){
                  que.emplace_back(xx, yy);
                  was[xx][yy]=3-was[x][y];
                }
              }
            }
          }
        }
        vector<int> cc(3, 0);
        for(auto &p : que){
          cc[was[p.first][p.second]]++;
        }
        int best = (cc[1] > cc[2] ? 1 : 2);
        for(auto &p : que){
          if(was[p.first][p.second] != best){
            alive[p.first][p.second] = 0;
          }
        }
      }
    }
  }
  int cc=n*n;
  FOR(i,0,2*n){
    FOR(j,0,2*n){
      if(alive[i][j]){
        cc--;
        cout << i << " " << j << endl;
        if(cc==0) return 0;
      }
    }
  }
}