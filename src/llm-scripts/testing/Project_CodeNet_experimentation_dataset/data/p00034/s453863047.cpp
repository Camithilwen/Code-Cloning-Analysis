//15
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
  double l[12];
  double ls[13]={};
  for(;;){
    for(int i=0;i<12;i++){
      (cin>>l[i]).ignore();
      if(!cin)return 0;
      ls[i+1]=ls[i]+l[i];
    }
    cout<<lower_bound(ls,ls+11,l[10]*ls[10]/(l[10]+l[11]))-ls<<endl;
  }
  return 0;
}