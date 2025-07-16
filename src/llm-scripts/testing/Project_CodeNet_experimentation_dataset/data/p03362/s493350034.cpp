#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int> p(60000,1);
  vector<int> q;
  for(int i=2;i<55556;i++){
    if(p[i]){
      for(int j=i*2;j<=55555;j+=i){
        p[j]=0;
      }
      if(i%5==1){
        q.push_back(i);
      }
    }
  }
  for(int i=0;i<N;i++){
    cout<<q[i];
    if(i-1==N){
      cout<<endl;
    }
    else{
      cout<<" ";
    }
  }
}