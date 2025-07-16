#include<bits/stdc++.h>
using namespace std;
int main(){
  int d,g,i,j,y,z,ans=1000;
  cin>>d>>g;
  vector<int> p(d),c(d);
  for(i=0;i<d;i++) cin>>p.at(i)>>c.at(i);
  for(i=0;i<(1<<d);i++){
    bitset<10> b(i);
    y=0;z=0;
    for(j=0;j<d;j++){
      if(b.test(j)){
        y+=p.at(j);
        z+=100*(j+1)*p.at(j)+c.at(j);
      }
    }
    for(j=d-1;j>=0;j--){
      if(g<=z) break;
      else if(!b.test(j)){
        if(g-z>100*(j+1)*(p.at(j)-1)){
          y+=p.at(j)-1;
          z+=100*(j+1)*(p.at(j)-1);
        }
        else{
          y+=(g-z)/(100*(j+1));
          if((g-z)%(100*(j+1))>0) y++;
          z=g;
        }
      }
    }
    if(g<=z&&y<ans) ans=y;
  }
  cout<<ans<<endl;
}