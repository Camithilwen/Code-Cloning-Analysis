#include <bits/stdc++.h>
using namespace std;

int MAX_N=262144*2;
vector<int64_t> seg(MAX_N*2-1);
int64_t qu(int a,int b,int k,int l, int r){
  if(r<=a||b<=l){
    return 0;
  }
  else if(a<=l&&r<=b){
    return seg[k];
  }
  else{
    int64_t X=qu(a,b,k*2+1,l,(l+r)/2);
    int64_t Y=qu(a,b,k*2+2,(l+r)/2,r);
    return X+Y;
  }
}
void pu(int64_t a,int b){
  int D=MAX_N-1+b;
  while(D>0){
    seg[D]+=a;
    D--;
    D/=2;
  }
  seg[0]+=a;
}

int main() {
  int N,Q;
  cin>>N>>Q;
  vector<int> p(N);
  for(int i=0;i<N;i++){
    cin>>p[i];
    p[i]--;
  }
  vector<tuple<int,int,int>> q(Q);
  for(int i=0;i<Q;i++){
    int a,b;
    cin>>a>>b;
    q[i]=make_tuple(b,a,i);
  }
  sort(q.begin(),q.end());
  vector<int> la(N,-1);
  vector<int> an(Q);
  int W=0;
  for(int i=0;i<Q;i++){
    int a,b,c;
    tie(a,b,c)=q[i];
    while(W<a){
      if(la[p[W]]!=-1){
        pu(-1,la[p[W]]);
      }
      la[p[W]]=W;
      pu(1,W);
      W++;
    }
    an[c]=qu(b-1,a,0,0,MAX_N);
  }
  for(int i=0;i<Q;i++){
    cout<<an[i]<<endl;
  }
}