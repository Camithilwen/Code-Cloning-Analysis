#include<bits/stdc++.h>
using namespace std;
typedef pair<double,string> P;
int main(){
  int n;
  while(cin>>n,n){
    P pr[55];
    for(int i=0;i<n;i++){
      string l;
      cin>>l;
      int p,a,b,c,d,e,f,s,m;
      cin>>p>>a>>b>>c>>d>>e>>f>>s>>m;
      double sumi=f*s*m-p;
      double sumt=a+b+c+(d+e)*m;
      pr[i]=P(-(sumi/sumt),l);
    }
    sort(pr,pr+n);
    for(int i=0;i<n;i++)cout<<pr[i].second<<endl;
    cout<<"#"<<endl;
  }
  return 0;
}

