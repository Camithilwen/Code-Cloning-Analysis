#include <bits/stdc++.h>
using namespace std;



int main(){
  //入力
  int A,B,M; cin>>A>>B>>M;
  vector<int> a(A); for(int i=0;i<A;i++) cin>>a.at(i);
  vector<int> b(B); for(int i=0;i<B;i++) cin>>b.at(i);
  
  //まずは(冷蔵庫の最安値)+(レンジの最安値を求める)
  int mina=100000,minb=100000;//まずはどちらも絶対にどのai,biよりも高くなるように設定する
  for(int i=0;i<A;i++) mina=min(mina,a.at(i));//競プロでよく使われる手段、最小値更新
  for(int i=0;i<B;i++) minb=min(minb,b.at(i));
  
  int ans=mina+minb;//割引券なしの最小値ペアが求まった
  
  //割引券込みのを求める
  for(int i=0;i<M;i++){
    int x,y,c; cin>>x>>y>>c; x--,y--;//入力、添え字調整
    int sub_ans=a.at(x)+b.at(y)-c;//i番目の割引込みの値段
    ans=min(ans,sub_ans);//最小値更新
  }
  
  cout<<ans<<endl;
  
  /*
  補足
  for文は書きにくいのでrepに差し替えてもいい
  最大値更新、最小値更新はある程度慣れたらchmin,chmaxを使った方がやりやすい、
  chmax,chminについては↓の2を参照
  https://qiita.com/drken/items/dc53c683d6de8aeacf5a
  */

  return 0;
}
