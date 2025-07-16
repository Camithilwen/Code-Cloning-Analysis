#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,Q;
  cin >> N >> Q;

  vector<int> data(N);
  for(int i=0; i<N; i++){
    cin >> data.at(i);
  }

  vector<int> cumsumL(N+1);
  vector<int> cumsumR(N+1);
  for(int i=1; i <= N; i++){
    cumsumL.at(i)= cumsumL.at(i-1)+ data.at(i-1);
    cumsumR.at(i)= cumsumR.at(i-1)+ data.at(N-i);
  }

  int QpopMAX= min(N, Q);
  int ans= 0;
  for(int Qpop=0; Qpop <= QpopMAX; Qpop++){
    for(int QpopL=0; QpopL <= Qpop; QpopL++){
      int QpopR= Qpop- QpopL;
      priority_queue<int, vector<int>, greater<int>> items;
      for(int i=0; i<QpopL; i++){
        items.push(data.at(i));
      }
      for(int i=1; i<=QpopR; i++){
        items.push(data.at(N-i));
      }

      int cand= cumsumL.at(QpopL)+ cumsumR.at(QpopR);
      ans= max(ans, cand);

      int Qpush= min(Q- Qpop, Qpop);
      for(int q=0; q<Qpush; q++){
        int cut_cand= items.top();
        if(cut_cand < 0){
          items.pop();
          cand-= cut_cand;
          ans= max(ans, cand);
        }
        else{
          break;
        }
      }
    }
  }

  cout << ans << endl;
}