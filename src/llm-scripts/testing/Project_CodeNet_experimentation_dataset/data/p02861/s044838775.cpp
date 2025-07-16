#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main(){
  double n;
  cin>>n;
  vector<double> x(n),y(n);
  rep(i,n) cin>>x[i]>>y[i];
  vector<int> t(n);
  rep(i,n) t[i]=i;
  double sum=0;
  int cnt=0;
  auto dis= [&](int i,int j){
    double dx=x[i]-x[j];
    double dy=y[i]-y[j];
    return sqrt(dx*dx+dy*dy);
  };
  do{
    for(int i=1;i<n;i++){
      sum+=dis(t[i],t[i-1]);
    }
    cnt++;
  }while(next_permutation(all(t)));
  printf("%.10f\n",sum/cnt);
}