#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX;
#define INFL LLONG_MAX;
typedef long long ll;
using namespace std;
int main(){

int A,B,i,sum=1,count=0;

cin >> A >> B;

for(i=0;i==0;i){

  if(sum<B){
    sum=sum-1+A;
    count++;
  }
  else{
    break;
  }
}
cout << count << endl;
}
