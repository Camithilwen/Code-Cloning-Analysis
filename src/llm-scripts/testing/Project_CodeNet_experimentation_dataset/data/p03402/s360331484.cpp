#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) begin(x), end(x)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

int main(){
  int a,b;
  cin>>a>>b;

  cout<<100<<' '<<100<<endl;

  string s1(100,'#'),s2(100,'.');
  a--; b--;
  rep(i,50){
    if(i%2==1) cout<<s1;
    else{
      rep(j,50){
	if(a){
	  cout<<".#";
	  a--;
	}
	else{
	  cout<<"##";
	}
      }
    }
    cout<<endl;
  }
  rep(i,50){
    if(i%2==0) cout<<s2;
    else{
      rep(j,50){
	if(b){
	  cout<<"#.";
	  b--;
	}
	else{
	  cout<<"..";
	}
      }
    }
    cout<<endl;
  }
  return 0;
}
