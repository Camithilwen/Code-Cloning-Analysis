#include<iostream>
using namespace std;

int n,k;
int d[10]={-1,-1,-1, -1, -1, -1, -1 ,-1,-1,-1};

bool check(int n){
  bool flag=true;
  int a;
  for(int i=n;i!=0;i/=10){
    a=i%10;
    for(int j=0;j<10;j++){
      if(a==d[j]) flag=false;
    }
  }
  return flag;
}

int main(){
  cin>>n>>k;
  for(int i=0;i<k;i++){
    cin>>d[i];
  }
  
  for(int i=n;i<100000;i++){
    bool flag=false;
    flag=check(i);
    if(flag) {
      cout << i << '\n';
      break;
    }
  }
    
  return 0;
}
