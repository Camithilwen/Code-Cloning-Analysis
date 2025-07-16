#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fr first
#define sc second
typedef vector<int> Vi;
typedef pair<int,int> Pii;
typedef pair<int,Pii> Pip; 
const int INF = (1<<30);
const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int main(){

  int n;
  int p[100] = {0};
  int rank[100] = {0};
  cin >> n;
  for(int i=0; i<n * (n - 1) / 2; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--; b--;
    if( c > d ) p[a] += 3;
    if( c < d ) p[b] += 3;
    if( c == d ) { p[a]++; p[b]++; }
  }

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if( i != j ) {
	if( p[i] < p[j] ) rank[i]++;
      }
    }
  }

  for(int i=0; i<n; i++) {
    cout << rank[i]+1 << endl;
  }
}