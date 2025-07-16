#include<bits/stdc++.h>
using namespace std;
int main(){
  long long N,L;
  cin >> N >> L;
  long long wa=0,sa=10000000000;
  for(int i=0; i<N; i++){
    long long kaage = L+i;
    wa += kaage;
    if(abs(sa) > abs(kaage)){
      sa = kaage;
    }
  }
    cout << wa-sa << endl;
}
