#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
#include<complex>
#define INF 2147483647
#define llINF 9223372036854775807
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long

using namespace std;
int main(){
  int n;
  while(cin>>n,n){
    const double Inf=1e9;
    vector<pair<double,string> >vegi;
    for(int i=0;i<n;i++){
      string str;cin>>str;
      double a,b,c,d,e,f,g,h,m;
      cin>>a>>b>>c>>d>>e>>f>>g>>h>>m;
      double time=b+c+d+m*(e+f);
      int value=m*h*g-a;
      vegi.pb(mp(Inf-(value/time),str));
    }
    sort(vegi.begin(),vegi.end());
    for(int i=0;i<n;i++)
      cout<<vegi[i].S<<endl;
    cout<<"#"<<endl;
  }
  return 0;
}

