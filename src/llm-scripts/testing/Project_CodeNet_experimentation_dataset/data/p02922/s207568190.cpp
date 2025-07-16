#include <iostream>
using namespace std;
int main(){
int A;
  int B;
  cin>>A>>B;
  int holes=1;
int ans=0;
  while(holes<B){
  holes--;
  holes+=A;
    ans++;
  }
  cout<<ans;
}