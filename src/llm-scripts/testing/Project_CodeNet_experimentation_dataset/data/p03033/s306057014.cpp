#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N,Q;
  cin >> N >> Q;
  vector<int> S(N),T(N),X(N);
  vector<int> D(Q);
  rep(i,N) cin >> S.at(i) >> T.at(i) >> X.at(i);
  rep(i,Q) cin >> D.at(i);

  set<P> s;
  vector<tuple<int,int,int>> a(N);
  vector<int> ans(Q,-1);

  rep(i,Q) s.insert(P(D.at(i),i));
  rep(i,N) a.at(i) = tie(X.at(i),S.at(i),T.at(i));
  sort(a.begin(),a.end());//位置でソート

  rep(i,N){//工事止めに対して
    int x,l,r;tie(x,l,r)=a.at(i);
    auto it=s.lower_bound(P(l-x,-1));
    while(it!=s.end()){
      if(it->first + x >= r) break;
      else{
        ans.at(it->second)=x;
        s.erase(it++);
      }
    }
    /*auto it=s.lower_bound(P(l,-1));//l以降のものを探す
    while(it!=s.end()){
      if(it->first>=r) break;//工事の影響がない
      ans.at(it->second)=x;//工事の影響でストップ
      s.erase(it++);//要素を消し，itをインクリメント
    }*/
  }
  rep(i,Q) cout << ans.at(i) << endl;
  return 0;
}