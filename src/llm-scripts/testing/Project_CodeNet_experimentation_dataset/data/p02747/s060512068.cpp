#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b

signed main(){
	string s; cin>>s;
  int n=s.size();
  if(n%2==1)cout<<"No";
  else{
	for(int i=n-1;i>=0;i--){
		if(i%2==0 && s[i]!='h'){
          cout<<"No"<<endl;
          return 0;
        }
		else if(i%2==1 && s[i]!='i'){
          cout<<"No"<<endl;
          return 0;
        }
    }
    cout<<"Yes"<<endl;
  }
  

    


	
	return 0;
}