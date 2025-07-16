#include <bits/stdc++.h>
using namespace std;

template< typename T >
size_t longest_increasing_subsequence(const vector< T > &a, bool strict) {
  vector< T > lis;
  for(auto &p : a) {
    typename vector< T >::iterator it;
    if(strict) it = lower_bound(begin(lis), end(lis), p);
    else it = upper_bound(begin(lis), end(lis), p);
    if(end(lis) == it) lis.emplace_back(p);
    else *it = p;
  }
  return lis.size();
}

int main(){
  int N;
  cin>>N;
  vector<int> A(N);
  for(int i=N-1;i>=0;i--){
    cin>>A[i];
  }
  
  cout<<longest_increasing_subsequence(A,false)<<endl;
  return 0; 
}

