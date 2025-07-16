#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll=long long;

int main(){
  int N,count=0;
  cin >> N;
  vector<int> L(N);
  rep(i,N) cin >> L.at(i);
  
  for(int i=0; i<N-2; i++){
    for(int j=i+1;j<N-1;j++){
       for(int k=j+1;k<N;k++){
         int a=L.at(i),b=L.at(j),c=L.at(k);
         
         if(a+b>c&&a+c>b&&b+c>a&&a!=b&&b!=c&&a!=c) count++;
       }
    }
  }
  
  cout << count << endl;
}
    
