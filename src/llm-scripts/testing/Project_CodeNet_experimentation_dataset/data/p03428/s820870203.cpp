#include<iostream>
#include<math.h>
#include<algorithm>
#include<tuple>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
typedef double db;
typedef tuple<bool,db> bod;
db Pi = 3.14159265358979;

db st(db t){
  t+=4*Pi;
  while(t>=0) t-=2*Pi;
  t+=2*Pi;
  return t;
}

bod J(db a,db b){
  if(a<=Pi){
    return make_tuple(!(a<=b && b<a+Pi),a+Pi-b);
  }
  else{
    return make_tuple(!(a<=b || b<a-Pi),st(a+Pi-b));
  }
}

int main(){
  int n,q,r;
  bool f;
  db x[100],y[100],m[100][100],M;
  cin >> n;
  if(n==2){
    cout<<0.5<<endl<<0.5<<endl;
    return 0;
  }
  fr(i,n) cin>>x[i]>>y[i];
  fr(i,n){
    fr(j,n){
      if(i != j){
        m[i][j]=st(atan2(x[j]-x[i],y[j]-y[i]));
      }
    }
    fr(j,n){
      if(i==j) continue;
      f=0;
      M=2*Pi;
      fr(k,n){
        if(k==i || k==j) continue;
//        cout<<i<<" "<<j<<" "<<k<<" "<<m[i][j]<<" "<<m[i][k]<<endl;
        bod G=J(m[i][j],m[i][k]);
        if(M>get<1>(G)){
          r=k;
          M=get<1>(G);
        }
        if(get<0>(G)){
          f=1;
          break;
        }
      }
      if(!f){
        q=j;
        break;
      }
    }
    if(f) cout<<0.0<<endl;
    else cout<<M/(2*Pi)<<endl;
  }
}