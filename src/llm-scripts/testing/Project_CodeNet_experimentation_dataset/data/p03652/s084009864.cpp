#include <bits/stdc++.h>
 
using namespace std;
inline void prep ()
{
  cin.tie (0);
  cin.sync_with_stdio (0);
};
const double pi = acos(-1.);
//printf(%.12lf\n,mid);
// __builtin_popcount(int) count 1's in binary
// get decimal part of number
/*
double intpart;
double thiss = modf((double)(n*m)/(double)k, &intpart);
*/
// round = (int)(num+.5)
long long mod = 1000000007;
 
long long mymod(long long num){
  if (num< 0 && !(num%mod == 0)){
    if (mod == 1){
      return 0;
    }
    return mod-abs(num)%mod;
  }else{
    return num%mod;
  }
}
 
/*string sentence = And I feel fine...;
    istringstream iss(sentence);
*/  
 
double eps = .000000001;

int main(){
  prep();
  int n, m;
  cin >> n >> m;
  int arr[n][m];
  for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
          cin >> arr[i][j];
          arr[i][j]--;
      }
  }
  int pointers[n] = {0};
  int cnts[m] = {0};
  int res = 0;

  for (int i=0; i<n; i++){
      cnts[arr[i][0]]++;
  }
  for (int i=0; i<m; i++){
      res = max(res, cnts[i]);
  }
  bool erased[m] = {false};
  for (int x=0; x<m-1; x++){
      int maxx = 0;
      int maxind = 0;
      for (int i=0; i<m; i++){
          if (cnts[i] > maxx){
              maxx = cnts[i];
              maxind = i;
          }
      }
      erased[maxind] = true;
      for (int i=0; i<n; i++){
          cnts[arr[i][pointers[i]]]--;
          while (erased[arr[i][pointers[i]]]){
              pointers[i]++;
          }
          cnts[arr[i][pointers[i]]]++;
          
      }
      maxx = 0;
      for (int i=0; i<m; i++){
          maxx = max(cnts[i], maxx);
      }
      res = min(res, maxx);
  }
  cout << res;
  return 0; 
}