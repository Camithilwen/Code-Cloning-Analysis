#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll;
const int inf = 0x3fffffff; const ll INF = 0x1fffffffffffffff; const double eps=1e-12;
template<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
//end



int main(){
   int n; cin>>n;
   vector<int> a(n),b(n);
   rep(i,0,n)cin>>a[i];
   rep(i,0,n)cin>>b[i];
   int d=0;
   rep(i,0,n){
      int idx=upper_bound(ALL(b),a[i])-b.begin();
      chmax(d,idx-i);
   }
   rotate(b.begin(),b.begin()+d,b.end());
   rep(i,0,n)if(a[i]==b[i]){
      puts("No"); return 0;
   }
   puts("Yes");
   rep(i,0,n)cout<<b[i]<<(i==n-1?'\n':' ');
   return 0;
}