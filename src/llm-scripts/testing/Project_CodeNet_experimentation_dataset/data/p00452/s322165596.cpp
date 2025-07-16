#include <bits/stdc++.h>
using namespace std;
#define Rep(i, N) for(int i = 0; i < N; i++)
 
int main()
{
  int N, M;
  
  while(cin >> N >> M, N || M) {
    int A[1005] = {0};
    vector<int>sum;
    int maxv = 0;
    sum.push_back(0);
    for(int i = 1; i <= N; i++) {
      cin >> A[i];
      Rep(j, i + 1) {
	if(A[i] + A[j] <= M) sum.push_back(A[i] + A[j]);
      }
    }
    sort(sum.begin(), sum.end());
    Rep(i, sum.size()) {
      maxv = max(maxv, sum[i] + *(upper_bound(sum.begin(), sum.end(), M - sum[i]) - 1));
    }
    cout << maxv << endl;
  }
  return 0;
}