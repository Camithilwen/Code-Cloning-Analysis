#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    string S;
    cin>>S;
    int w;
    cin>>w;
    int a=S.size();
  	if(w!=1){
    for(int i=1; i<a+1; i++){
        if(i%w==1){
            cout<<S[i-1];
        }
    }
    }
  else{
rep(i,S.size()){
  cout<<S[i];
}
  }
    cout<<""<<endl;
}
