#include<bits/stdc++.h>
#define N 105
using namespace std;
typedef pair<int,int> P;
int n,a,b,c,d,ans[N],cnt,prevx;
P x[N];

int main(){
  cin>>n;
  for(int i=0;i<n;i++)x[i].second=i+1;
  for(int i=0;i<n*(n-1)/2;i++){
    cin>>a>>b>>c>>d;
    if(c==d)x[a-1].first++,x[b-1].first++;
    else if(c<d)x[b-1].first+=3;
    else x[a-1].first+=3;
  }
  sort(x,x+N,greater<P>());
  cnt=1;
  prevx=x[0].first;
  for(int i=0;i<n;i++){
    if(prevx>x[i].first){
      cnt=i+1;
      prevx=x[i].first;
    }
    ans[x[i].second-1]=cnt;
  }
  for(int i=0;i<n;i++)
    cout<<ans[i]<<endl;
  return 0;
}