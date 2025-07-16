#include<iostream>
#include<string>
#include<numeric>
#include<set>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef long long li;
#define ceil(a,b) (((a)+(b)-1)/(b))
#define dist(a,b) max((a)-(b),(b)-(a))
#define yn(i) print((i)?"Yes":"No")
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



int main(){
  int h,w; cin >>h >>w;
  int a,b; cin >>a >>b;
  int s=0;
  rep(i,h){
    if(i==b) s^=1;
    rep(j,w){
      if(j==a) s^=1;
      printf("%d",s);
    }
    printf("\n");
    s^=1;
  }
}