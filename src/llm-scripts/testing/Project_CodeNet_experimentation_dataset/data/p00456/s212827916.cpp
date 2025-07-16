#include<bits/stdc++.h>

using namespace std;

int main()
{
  vector<int> W;
  vector<int> K;

  for(int i = 0;i < 20;++i){
    int a;
    cin>>a;
    
    if(i < 10){
      W.push_back(a);
    }
    else{
      K.push_back(a);
    }
  }

  sort(W.begin(),W.end());
  reverse(W.begin(),W.end());
  sort(K.begin(),K.end());
  reverse(K.begin(),K.end());

  int a = 0;
  int W_p = 0;
  int K_p = 0;
  for(int e : W){
    W_p += e;
    ++a;

    if(a == 3){
      a = 0;
      break;
    }
  }

  for(int e : K){
    K_p += e;
    ++a;

    if(a == 3){
      break;
    }
  }

  cout<<W_p<<" "<<K_p<<endl;
  return 0;
}
