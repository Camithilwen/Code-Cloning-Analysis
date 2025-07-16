#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M;cin>>N>>M;bool F=false;int A=-1,B=-1,C=-1;
  for (int X=0;X<=N;X++){
    for (int Y=0;Y<=N;Y++){
      if (X+Y<=N&&X*10000+Y*5000+(N-X-Y)*1000==M){
        A=X;B=Y;C=(N-X-Y);F=true;break;
      }
    }
  }
  if(!F){
    cout<<-1<<" "<<-1<<" "<<-1<<endl;return 0;
  }
  cout<<A<<" "<<B<<" "<<C<<endl;
}