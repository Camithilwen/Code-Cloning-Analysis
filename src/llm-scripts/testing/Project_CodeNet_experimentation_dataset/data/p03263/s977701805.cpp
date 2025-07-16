#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  int H,W;
  cin >> H >> W;
  vector<vector<int>> A(H,vector<int>(W));
  REP(i, H){
    REP(j, W){
      cin >> A.at(i).at(j);
    }
  }

  vector<vector<int>> ans(4,vector<int> ());
  int flag = 0;
  REP(i,H){
    if(i%2==0){
      REP(j,W){
        if(A.at(i).at(j)%2==1&&flag==0){
          flag=1;
          continue;
        }
        if(flag==1){
          ans.at(2).push_back(i);
          ans.at(3).push_back(j);
          if(j==0){
            ans.at(0).push_back(i-1);
            ans.at(1).push_back(j);
          }else{
            ans.at(0).push_back(i);
            ans.at(1).push_back(j-1);
          }
        }
        if(A.at(i).at(j)%2==1&&flag==1){
          flag=0;
        }
      }
    }else{
      REPR(j,W-1){
        if(A.at(i).at(j)%2==1&&flag==0){
          flag=1;
          continue;
        }
        if(flag==1){
          ans.at(2).push_back(i);
          ans.at(3).push_back(j);
          if(j==W-1){
            ans.at(0).push_back(i-1);
            ans.at(1).push_back(j);
          }else{
            ans.at(0).push_back(i);
            ans.at(1).push_back(j+1);
          }
        }
        if(A.at(i).at(j)%2==1&&flag==1){
          flag=0;
        }
      }
    }
  }

  cout << ans.at(0).size() << endl;
  REP(i,ans.at(0).size()){
    REP(j,3){
      cout << ++ans.at(j).at(i) << " ";
    }
    cout << ++ans.at(3).at(i) << endl;
  }
}