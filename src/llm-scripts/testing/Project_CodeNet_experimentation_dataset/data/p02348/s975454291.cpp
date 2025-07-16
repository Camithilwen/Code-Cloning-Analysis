#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#define REP(i,n) for(int i = 0;i < (n);i++)
#define pb push_back
using namespace std;
const int INF = 1e9;
typedef long long ll;

int main(){
  int n,q;
  cin >> n >> q;
  vector <int> res;
  int a[n];
  int sq = sqrt(n);
  int nsq = n/sq+1;
  int lazy[nsq];
  fill(a,a+n,2147483647);
  fill(lazy,lazy+nsq,-1);
  REP(i,q){
    int z;
    cin >> z;
    if(z == 0){
      int s,t,x;
      cin >> s >> t >> x;

      /*if(s == t){
	a[s] = x;
	}*/
      if(t/sq == s/sq){
	if(lazy[t/sq] >= 0){
	  fill_n(a+(t/sq)*sq,sq,lazy[t/sq]);
	  lazy[t/sq] = -1;
	}
	if(t-s+1 == sq){
	  lazy[t/sq] = x;
	}
	else{
	  fill_n(a+s,t-s+1,x);
	}
	//cout << "debug1" <<endl;
      }

      else{
	//cout << "debug3" << endl;
	int f = s,to = t;
	while(to%sq != (sq - 1)){
	  to--;
	}
	while(f%sq != 0){
	  f++;
	}
	if(lazy[t/sq] >= 0){
	  fill_n(a+(t/sq)*sq,sq,lazy[t/sq]);
	}
	if(lazy[s/sq] >= 0){
	  fill_n(a+(s/sq)*sq,sq,lazy[s/sq]);
	}
	fill_n(a+to+1,t-to,x);
	lazy[t/sq] = -1;
	fill_n(a+s,f-s,x);
	lazy[s/sq] = -1;
	f = f/sq;
	to = to/sq;
	if(f <= to){
	  fill_n(lazy+f,to-f+1,x);
	}
	
      }
      /*REP(i,n)
	cout << a[i] << "  ";
	cout << endl;*/
    }
    else{
      int x;
      cin >> x;
      int te = x / sq;
      
      if(lazy[te] < 0){
	//cout << a[x] << endl;
	res.pb(a[x]);
      }
      else{
	fill_n(a+te*sq,sq,lazy[te]);
	lazy[te] = -1;
	//cout << a[x] << endl;
	res.pb(a[x]);

      }
      
    }
    
  }
  for(int i = 0;i < res.size();i++){
    cout << res[i] << endl;
  }
  //cout << res.size() << endl;
  return 0;
}