#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

vector<int> ball(200005,0);

void putball(int n){
  for(int i=1; i<=sqrt(n); i++){
    if(n%i==0){
      ball.at(i)++;
      if(i!=n/i)ball.at(n/i)++;
      //cout << "putball " << i << endl;
    }
  }
}

int main(){
  int n;
  cin >> n;

  vector<int> a(n);
  rep(i,n) cin >> a.at(i);

  int ballcount = 0;
  vector<int> b;

  rep(i,n){
    int j = n-i;
    if((ball.at(j)%2)!=a.at(j-1)){
      putball(j);
      b.push_back(j);
      ballcount++;
      //cout << "putball " << j << endl;
    }
  }

  if((ball.at(1)%2)==a.at(0)){
    cout << ballcount << endl;
    rep(i,b.size()) cout << b.at(i) << " ";
  }else{
    cout << "-1";
  }
  
  //cout << "hoge";
  //rep(i,n) cout << ball.at(i+1) << " ";
}