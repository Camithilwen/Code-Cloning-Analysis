#include<iostream>
#include<string>
#include<numeric>
#include<set>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef long long li;
#define minimize(a,b) (a>(b)?a=(b),1:0)
#define maximize(a,b) (a<(b)?a=(b),1:0)
#define ceil(a,b) (((a)+(b)-1)/(b))
#define yn(i) ((i)?"Yes":"No")
#define chmin(a,b) (a>(b)?a=(b),1:0)
#define abs(n) max((n),-(n))
#define dist(a,b) max((a)-(b),(b)-(a))
#define chmax(a,b) (a<(b)?a=(b),1:0)
#define repa(i,a,n) for(int i=(a);i<(n);i++)
#define MOD 1000000000
#define rep(i,n) for(int i=0;i<(n);i++)

#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }

// Container コンテナ型, map以外
template< template<class ...> class Ctn,class T>
std::ostream& operator<<(std::ostream& os,const Ctn<T>& v){
  auto itr=v.begin();
  while(itr!=v.end()){
    if(itr!=v.begin())cout << " ";
    cout << *(itr++);
  }
  return os;
}




string key="keyence";

void add(char m,string s,set<string> st){
  int n=s.size();
  rep(i,n){
    if(s[i]!=m) continue;
    string t;
    repa(j,i,n){
      t.push_back(s[j]);
      st.insert(t);
    }
  }
}

int gcd(int a,int b){
  return b?gcd(b,a%b):a;
}

int main(){
  string s; cin >>s;
  int d=0,ans=0,n=s.size();
  rep(i,n){
    if(s[i]=='S'){
      d+=1; continue;
    }
    if(d>0){
      d-=1; continue;
    }
    ans++;
  }
  print(ans+d);
}



