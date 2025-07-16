#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,X,ans=0;
  cin >> N >> X;
  vector<int>vec(N);
  for(int i=0; i<N; i++){
    cin >> vec[i];
  }
  sort(vec.begin(),vec.end());
  for(int i=0; i<N; i++){
    if(X<vec[i]){
      break;
    }
    else{
    ans++;
    X -= vec[i];
    }
  }
  if(ans == N && X>0){
    ans--;
  }
  cout << ans << endl;
}
