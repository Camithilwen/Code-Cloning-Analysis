
#include <bits/stdc++.h>
#define rep(i,n) for (double i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<double,double> P;
const int INF=1001001001;


// Morris-Pratt
template<typename T>
struct MP {
  int n;
  T t;
  vector<int> a;
  MP() {}
  MP(const T& t): t(t) {
    n = t.size();
    a = vector<int>(n+1);//便宜上最初に-1を入れるため（1 indexにした方が良い)
    a[0] = -1;
    int j = -1;
    for (int i = 0; i < n; ++i) {
      while (j != -1 && t[j] != t[i]) j = a[j];//次の文字が一致するようなaを見つける
      j++;
      a[i+1] = j;
    }
  }
  int operator[](int i) { return a[i];}//添字アクセスできるように
  vector<int> findAll(const T& s) {
    vector<int> res;
    int j = 0;
    for (int i = 0; i < s.size(); ++i) {
      while (j != -1 && t[j] != s[i]) j = a[j];
      j++;
      if (j == n) {
        res.push_back(i-j+1);
        j = a[j];
      }
    }
    return res;
  }
};


int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  vector<int> b(n);
  vector<int> a1(n);
  vector<int> b1(n);

  rep(i,n)cin>>a[i];
  rep(i,n)cin>>b[i];
  rep(i,n-1){
    a1[i+1]=a[i]^a[i+1];
  }
  rep(i,n-1){
    b1[i+1]=b[i]^b[i+1];
  }
  a1[0]=a[0]^a[n-1];
  b1[0]=b[0]^b[n-1];

  vector<int> A=a1;
  A.insert(A.end(), A.begin(), A.end());
//  rep(i,A.size())cout<<A[i];
  MP <vector<int>> mp(b1);


  vector<int> res=mp.findAll(A);
  rep(i,res.size()){
    if (res[i]>=n)continue;
    int now=res[i];
    int x=b[0]^a[now];
    cout<<res[i]<<" "<<x<<endl;
  }

}
