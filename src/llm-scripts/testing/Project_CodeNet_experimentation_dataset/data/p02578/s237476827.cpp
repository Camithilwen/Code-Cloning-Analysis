#include<iostream>
using namespace std;

int main(){
  int N;
  int A,AA;
  long long ans=0;
  cin>>N;
  int times=N-1;
  int s;
  cin>>A;
  for(int i=0;i<times;i++){
    cin>>AA;
    if(A>AA){
      s=A-AA;
      ans+=s;
      AA+=s;
      A=AA;
    }else{
      A=AA;
    }
  }
  cout<<ans<<endl;
}
