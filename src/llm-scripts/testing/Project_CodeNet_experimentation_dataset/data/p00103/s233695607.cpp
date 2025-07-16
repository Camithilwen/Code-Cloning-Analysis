#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main(){
  int n;
  string event;
  int base=0;
  int inning=0;
  cin>>n;
  vector<int> point(n);
  int outnum=0;
  while(inning<n){
    cin>>event;
    if(event=="HIT"){
      base<<=1;
      base|=1;
      if(base&8){
        point[inning]++;
        base^=8;
      }
    }else if(event=="HOMERUN"){
      point[inning]+=1;
      for(int i=0;i<3;i++)
        point[inning]+=(base>>i)&1;
      base=0;
    }else if(event=="OUT"){
      outnum++;
      if(outnum>2){
        outnum=0;
        inning++;
        base=0;
      }
    }
  }
  for(int p:point)
    cout<<p<<endl;
}