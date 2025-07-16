#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;
int inf = 10000000;
int n;
vector<int> a;
int partition(int p, int r){
  int x = a[r-1];
  int i = p-1;
  for(int j=p; j<r; j++){
    if( a[j] <= x ){
      // i = i + 1;
      swap(a[++i], a[j]);
    }
  }
  // swap(a[i+1], a[r]);
  return i;
}

int main(){
  cin >> n;
  a.resize(n);
  for(int i=0; i<n; i++) cin >> a[i];

  int p = partition(0, n);

  for(int i=0; i<n; i++){
    if( i == p ) cout << "[" << a[i] << "]";
    else cout << a[i];
    if( i == n-1 ) cout << endl;
    else cout << " ";
  }

  return 0;
}