#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for (ll i=0; i<n; ++i)
#define all(c) begin(c),end(c)
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
/*
(H,W)
(i,j)
1行ずつよまなきゃ
ああ、そういうことか
OXXXO
XXXXO
1
2になるのか
OXXXOXXOX
XXXOXXXXO
これはない

2e5)^2は無理
ええ・・・BITなら無理・・・
12345678
OOOXXXOO (1,1) (7,1) 4-6
OXXXXXXO (1,2) (8,2) 2-7
XXXXOOOO (5,7) (8,3) 1-4
OOOOOXXX (5,8) (9,3)みたいな

OOOXXXXX 4-8
XXOOOOOO 1-2
最高効率と手前保存しておくとか？

管理むずい

W通り保持・・・
12345678 //(スタート位置、今いるW）
OOOXXXOO {(1,1),(2,2),(3,3),(7,7),(8,8)} //0+1 {0,0,0,0,0}
OXXXXXXO {(1,1),(8,8)} //0+2 {0,0}
XXXXOOOO {(1,5),(8,8)} //0+3 {4,0}
OOOOOXXX {(1,5)} //(5-1)+4 {4}

mapとmultiset...
mapにlower_bound？
おしりから見ていくとか

(今いる位置、スタート位置）か。

・setにpair
set<pair<ll,ll>> S;
S.lower_bound({a,b});
a優先でb順に並んでる。

・eraseした後のitr
S.erase(itr);
itr++;
eraseした後ポインタの場所変わっちゃうので1つ先がとれるとは限らない。

S.erase(itr++);
erase処理前の移動でちゃんと1つ先がとれる。

おぎゃあああああああああああ

OOXX
XXOO
XXOO
OOOX
XXXO
XXXX
XXXO

最後消えてないじゃん
*/

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  ll H,W; cin>>H>>W;
  set<pair<ll, ll>> POS;
  multiset<ll> SC;
  rep(i, H){
    ll a, b, ans=0; cin>>a>>b;
    if (i == 0){
      for(ll j=1; j<a; j++){
        POS.insert({j, j});
        SC.insert(0);
      }
      for(ll j=b+1; j<=W; j++){
        POS.insert({j, j});
        SC.insert(0);
      }
    }
    else{
      auto itr1 = POS.lower_bound({a, -1});
      ll v1, v2;
      bool del = false;
      while(itr1 != POS.end() && itr1->first <= b){
        v1 = itr1->first;
        v2 = itr1->second;
        SC.erase(SC.find(v1 - v2));
        POS.erase(itr1++);
        del = true;
      }
      if (del && b < W && itr1->first != b+1){
        POS.insert({b+1, v2});
        SC.insert(b+1 - v2);
      }
    }
    if (SC.size() == 0){
      cout << -1 << endl;
      continue;
    }
    ans = *SC.begin();
    cout << ans + i + 1 << endl;

/*
cout<<"i:"<<i<<" SC.size():" << SC.size() << " POS.size():" << POS.size() << endl;
cout<<"SC:";
auto itr = SC.begin();
while (itr != SC.end()){
  cout<<*itr<<" ";
  itr++;
}
cout<<"POS:";
auto pitr = POS.begin();
while (pitr != POS.end()){
  cout<<"("<< pitr->first<<", "<<pitr->second<<") ";
  pitr++;
}
cout<<endl;
*/

  }
}