#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{
  ll x;
  cin>>x;
  if(x<11){
    if(x<=6){
      cout<<1<<endl;
    }else{
      cout<<2<<endl;
    }
  }else{
    if(x%11==0){
      cout<<2*(x/11)<<endl;
    }else if(x%11<=6){
      cout<<2*(x/11)+1<<endl;
    }else{
      cout<<2*(x/11)+2<<endl;
    }
  }


  return 0;
}
