#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M;
  cin >> N >> M;
  vector<bool>vec(N,true);
  vector<int>F(N);
  int WA=0,AC=0;
  for(int i=0; i<M; i++){
    int p;
    string S;
    cin >> p >> S;
    if(vec[p-1] && S == "WA"){
      WA++;
      F[p-1]++;
    }
    if(vec[p-1] && S == "AC"){
      AC++;
      vec[p-1]=false;
    }
  }
  for(int i=0; i<N; i++){
    if(vec[i]){
      WA -= F[i];
    }
  }
  cout << AC << " " << WA << endl;
}
