#include <bits/stdc++.h>
using namespace std;

int n, k;

double kitaichi(vector<int> p, int start, int k){
  double ans;
  for (int i = 0; i < k; i++){
    double sum = 0;
    for (int j = 1; j <= p[start+i]; j++){
      sum += j;
    }
    ans += sum/p[start+i];
  } 
  return ans;
}
 
int main() {
  cin >> n >> k;
  vector<int> p(n);
  for (int i = 0; i < n; i++){
    cin >> p.at(i);
  }
  int sum = 0;
  int start;
  int s = 0;
  for (int i = 0; i  < 1; i++){
    for (int j = 0; j < k; j++){ 
      s += p.at(i+j);
    }
    sum = s;
    start = i;
  }
  for (int i = 1; i + k <= n; i++){
    s += p.at(i+k-1);
    s -= p.at(i-1);
    if (sum < s){
      sum = s;
      start = i;
    }
  }
  cout << fixed << setprecision(15) << kitaichi(p, start, k) << endl;
}