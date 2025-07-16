#include<bits/stdc++.h>
using namespace std;
typedef complex<double> P;

vector<P> cal(vector<P> &v,double a,double b){
  vector<P> res;
  for(int i=0;i<v.size();i++){
    double l=v[i].real(),r=v[i].imag();
    if(l<=a&&b<=r)res.push_back(P(l,a)),res.push_back(P(b,r));
    else if(l<=a&&a<=r)res.push_back(P(l,a));
    else if(l<=b&&b<=r)res.push_back(P(b,r));
    else if(a>l||r>b)res.push_back(v[i]);
  }
  return res;
}

int main(){
  int n;
  cin>>n;
  double x,y;
  P p[100];
  for(int i=0;i<n;i++)cin>>x>>y,p[i]=P(x,y);
  for(int i=0;i<n;i++){
    vector<P> v;
    v.push_back(P(-M_PI,M_PI));
    for(int j=0;j<n;j++){
      if(i==j)continue;
      P a=P(0,-1)*(p[j]-p[i]);
      double d=arg(a);
      if(d>0)v=cal(v,d,M_PI),v=cal(v,-M_PI,d-M_PI);
      else v=cal(v,d,d+M_PI);
    }
    double ans=0;
    for(int j=0;j<(int)v.size();j++)ans+=v[j].imag()-v[j].real();
    cout<<ans/2/M_PI<<endl;
  }
  return 0;
}