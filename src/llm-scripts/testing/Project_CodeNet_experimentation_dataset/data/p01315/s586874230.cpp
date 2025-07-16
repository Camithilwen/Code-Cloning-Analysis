#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,n) for(i=a;i<n;i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

typedef vector<int> vi;
typedef pair<int,int> pii;

int main(void) {
  int i,j;
  int n;
  while(1){
    cin>>n;
    if(n==0)break;
    cin.ignore();
    vector<string> name(n);
    pair<double,string> pp[50];
    rep(i,n){
      int p,a,b,c,d,e,f,s,m;
      cin>>pp[i].second>>p>>a>>b>>c>>d>>e>>f>>s>>m;
      int t=a+b+c+(d+e)*m;
      int in=f*s*m-p;
      pp[i].first=(double)in/t;
      pp[i].first*=-1;
    }
    sort(pp,pp+n);
    rep(i,n)cout<<pp[i].second<<endl;
    cout<<"#"<<endl;
  }
}