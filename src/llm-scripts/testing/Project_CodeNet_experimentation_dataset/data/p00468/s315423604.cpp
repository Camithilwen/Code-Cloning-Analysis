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

  int n, m;
  int a[10000], b[10000];
  while( cin >> n >> m, n + m ) {
    map<int, int> maps;
    set<int> all;
    
    for(int i=0; i<m; i++) {
      cin >> a[i] >> b[i];
      if( a[i] == 1 ) {
	maps[b[i]] = 1;
	all.insert(b[i]);
      }
    }
    
    for(int i=0; i<m; i++) {
      if( maps[a[i]] == 1 ) {
	all.insert(b[i]);
      }
      if( maps[b[i]] == 1 ) {
	if( a[i]!= 1 ) {
	  all.insert(a[i]);
	}
      }
    }
    
    cout << all.size() << endl;
  }
}