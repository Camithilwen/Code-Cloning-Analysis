#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B;
  cin>>A>>B;
  int count_ana=1,count_ans=0;
  while(count_ana<B){
  count_ana+=A-1;
  count_ans++;  
  }
  cout<<count_ans<<endl;
}
