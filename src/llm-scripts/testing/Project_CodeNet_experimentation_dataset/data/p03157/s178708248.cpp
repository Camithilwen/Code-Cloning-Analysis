#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
  int H,W;
  cin >> H >> W;
  vector<string> A(H);
  REP(i, H) cin >> A[i];
  
  vector<vector<int>> dist(H,vector<int> (W,-1));
  ll ans = 0;
  REP(i,H){
    REP(j,W){
      if(A.at(i).at(j)=='#'&&dist[i][j]==-1){
        ll cntblack = 1;
        ll cntwhite = 0;
        queue<P> que;
        que.push(make_pair(i,j));
        dist[i][j]=0;
        while(!que.empty()){
          int vy = que.front().first;
          int vx = que.front().second;
          que.pop();
          REP(k,4){
            int nvy = vy+dy[k];
            int nvx = vx+dx[k];
            if(nvy<0||nvy>H-1||nvx<0||nvx>W-1||dist[nvy][nvx]!=-1||(A[vy][vx]=='#'&&A[nvy][nvx]!='.')||(A[vy][vx]=='.'&&A[nvy][nvx]!='#')) continue;
            dist[nvy][nvx]=0;
            que.push(make_pair(nvy,nvx));
            if(A[nvy][nvx]=='#'){
              cntblack++;
            }else{
              cntwhite++;
            }
          }
        }
        ans+=cntblack*cntwhite;
      }
    }
  }

  cout << ans << endl;
}