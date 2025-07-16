#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;
  vector<int>A(N);
  vector<int>B(N);
  vector<int>C(N);
  vector<long long>D(N);
  for(int i=0;i<N;i++)cin>>A[i];
  for(int i=0;i<N;i++)cin>>B[i];
  for(int i=0;i<N;i++)cin>>C[i];
  sort(A.begin(),A.end());
  sort(C.begin(),C.end());
  long long ans=0;
  for(int i=0;i<N;i++){
    ans+=(N-(A.end()-lower_bound(A.begin(),A.end(),B[i])))*(C.end()-upper_bound(C.begin(),C.end(),B[i]));
  }
  cout<<ans<<endl;
}