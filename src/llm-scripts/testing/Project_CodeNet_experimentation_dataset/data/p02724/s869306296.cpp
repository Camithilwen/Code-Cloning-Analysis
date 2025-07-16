#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;
int cnt=0;
void bubbleSort(vector<int> &A, int N){ // N 個の要素を含む 0-オリジンの配列 A
  int flag = 1; // 逆の隣接要素が存在する
    while (flag){
      flag = 0;
      for (int j=N-1;j>=1;j--){
        if (A[j] < A[j-1]){
          cnt++;
          swap(A[j],A[j-1]);
          flag = 1;
        }
      }
    }
}
int main() {
  int64_t X;
  cin>>X;
  cout<<X/500*1000+X%500/5*5<<endl;;
  return 0;  
}