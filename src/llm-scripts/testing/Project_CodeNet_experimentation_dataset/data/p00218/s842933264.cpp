#include<vector>
#include<iostream>
using namespace std;


string solve(){
  vector<int> a;
  for(int i=0;i<3;i++){
    int tmp;
    cin>>tmp;
    a.push_back(tmp);
  }

  for(int i=0;i<a.size();i++){
    if(a[i]==100)return "A";
  }
  if(a[0]+a[1]>=90*2)return "A";
  int ave = (a[0]+a[1]+a[2])/3;
  if(ave>=80)return "A";
  if(ave>=70)return "B";
  if(ave>=50)if(a[0]>=80||a[1]>=80)return "B";
  return "C";
}


int main(){
  int n;
  while(cin>>n,n!=0){
    for(int i=0;i<n;i++){
      cout<<solve()<<endl;
    }
  }
}