#include<iostream>
#include<set>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long li;
#define repa(i,a,n) for(int i=(a);i<(n);i++)
#define yn(i) print((i)?"Yes":"No")
#define rep(i,n) for(int i=0;i<(n);i++)

#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }
// pair 型
template<class S,class T>
std::ostream& operator<<(std::ostream& os, const pair<T,S>& p){
  cout << "(" << p.first << "," << p.second << ")";
  return os;
}

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
// map 型
template<class S,class T>
std::ostream& operator<<(std::ostream& os, const map<S,T>& mp){
  for(const pair<S,T>& x: mp){
    cout << "[" << x.first << "]=" << x.second << " ";
  }
  return os;
}

int main(){
  set<char> st;
  rep(i,26) st.insert('a'+i);
  string s; cin >>s;
  int n=s.size();
  rep(i,n) st.erase(s[i]);
  if(st.empty()){
    print("None");
  }else{
    print(*st.begin());
  }
}



