#include <bits/stdc++.h>
using namespace std;

int main() {
  long N;
  cin>>N;
  vector<vector<long>> a(100005,vector<long>(2));
  vector<vector<long>> b(100005,vector<long>(2));
  long al=0,bl=0;
  for(int i=0;i<N;i++){
    long v;
    cin>>v;
    if(i%2==0) a[v][0]++,al++;
    else b[v][0]++,bl++;
  }
  for(int i=0;i<100005;i++) a[i][1]=i,b[i][1]=i;

  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());
  long ans1=1234567890;
  long x=a[0][0];
  long y=b[0][0];
  if(a[0][1]!=b[0][1]){
    ans1=(al-x)+(bl-y);
  }
  long ans2=1234567890;
  x=a[1][0];
  y=b[0][0];
  if(a[1][1]!=b[0][1]){
    ans2=(al-x)+(bl-y);
  }
  long ans3=1234567890;
  x=a[0][0];
  y=b[1][0];
  if(a[0][1]!=b[1][1]){
    ans3=(al-x)+(bl-y);
  }
  cout<<min(min(ans1,ans2),ans3)<<endl;
  }
