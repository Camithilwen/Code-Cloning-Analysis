#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  int n, k;
  cin >> n >> k;
  double ans = 0.0, ex = 0.0;
  vector<double> p(n);
  for(int i=0; i<n; i++){
    cin >> p[i];
  }
  for(int i=0; i<k; i++){
    ex += 1+p[i];
  }
  if(n==k){
    ex /= 2.0;
    cout << ex << endl;
    return 0;
  }
  ans = ex;
  for(int i=k; i<n; i++){
    ex = ex-p[i-k]+p[i];
    ans = max(ans, ex);
  }
  ans /= 2.0;
  printf("%.6lf", ans);
  return 0;
}
