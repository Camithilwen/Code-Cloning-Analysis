#include <iostream>
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(void){
  int N;
  cin >> N;
  int A[N];
  rep(i, N)
    cin >> A[i];
  // 入力終了

  // A[]中の負の数の数
  int negative_num = 0;
  rep(i, N)
    if(A[i] < 0)
      negative_num++;

  long long ans = 0;

  // 負の数が偶数個なら，操作の繰り返しで全て正にできる
  if(negative_num % 2 == 0){
    rep(i, N)
      ans += abs(A[i]);
  }
  // 奇数個なら，1つを残して全て正にできる
  // 絶対値が一番小さいものを負にしておけばOK
  else{
    // 絶対値が一番小さいものを探す
    int abs_min = 1000000000;
    rep(i, N)
      if(abs(A[i]) < abs_min)
	abs_min = abs(A[i] );

    // 絶対値が最小のもの以外は正で足す
    // 絶対値が最小のものは負で足す
    rep(i, N)
      if(abs(A[i]) != abs_min)
	ans += abs(A[i] );
      else
	ans -= abs(A[i] );
  }

  // 解答
  cout << ans << endl;

  return 0;
}
