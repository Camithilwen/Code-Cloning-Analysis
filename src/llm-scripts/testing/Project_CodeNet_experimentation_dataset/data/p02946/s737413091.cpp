#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<ll,int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int k, x;
  cin >> k >> x;
  for(int i=x-k+1; i<x+k; i++){
    if(i==x+k-1) cout << i << endl;
    else cout << i << " ";
  }
  return 0;
}
