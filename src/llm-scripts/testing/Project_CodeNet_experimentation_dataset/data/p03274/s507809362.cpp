#include "bits/stdc++.h"
using namespace std;
using ll = long long;

template <typename T>
void print_vec(const vector<T>& v, bool is_reverse=false, ll num=0){
  if(num == 0) num = (ll)v.size();
  if(is_reverse) for(ll i=num-1; i>=0; i--){ cout<<v[i]; if(i!=0) cout<<" ";}
  else for(ll i=0; i<num; i++){ cout<<v[i]; if(i!=num-1) cout<<" ";}
  cout << endl;
}

template <typename T>
void print_pairvec(const vector<T> &v, ll num=0){
  if(num == 0) num = (ll)v.size();
  cout << endl;
  for(ll i=0; i<num; i++){ cout << v[i].first << " " << v[i].second << endl;}
}

template <typename T>
void print_vec2(const vector<vector<T>>& v){
  cout << endl; cout << "       ";
  for(ll i=0; i<v[0].size(); i++) cout << i << "   "; 
  cout << endl;
	for(ll i=0; i<v.size(); i++){
		cout << "i=" << i << ":   ";
		for(ll j=0; j<v[i].size(); j++){
			if(v[i][j] == 0) cout << "\x1B[0m" << v[i][j] << "   ";
      else cout << "\x1B[31m" << v[i][j] << "   ";//https://stackoverrun.com/ja/q/12618775
		}
		cout << "\x1B[0m" << endl;
	}
}

int main(){
  int N, k;
  cin >> N >> k;
  vector<int> x(N);
  for(int i=0; i<N; i++) cin >> x[i];

  // vector<int> anses;
  // const int INF =  2e8+1;
  const int INF = 1e8 + 1e8 + 1e8 + 1;//
  int ans = INF;
  for(int i=0; i<N; i++){
    if(i+k-1 >= N) break;
    int sx = x[i];
    int gx = x[i+k-1];
    if(sx < 0 && gx < 0) ans = min(ans, -sx);
    else if(sx >= 0  &&  gx >= 0) ans = min(ans, gx);
    else if(sx <= 0 && 0 <= gx){
      int tmp = min(2*(-sx) + gx,  -sx + 2*gx);
      ans = min(ans, tmp);
    }
  }

  cout << ans << endl;
  return 0;
}
