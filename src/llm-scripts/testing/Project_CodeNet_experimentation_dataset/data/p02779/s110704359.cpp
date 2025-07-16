#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, ai;
  cin >> N;
  map <int,int> A;
  for(int i=0;i<N;i++){
    cin >> ai;
    if(A.count(ai) > 0){ cout << "NO" << endl; return 0;}
    else A[ai] = 1;
  }
  cout << "YES" << endl;
}