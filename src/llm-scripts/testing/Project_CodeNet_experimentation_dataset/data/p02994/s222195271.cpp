#include<queue>
#include<stack>
#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
#include<functional>
#include<deque>
#include<list>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  int k,n,l,i;
  int ans=(1<<29);
  cin >> n >> l;
  vector<int> x(n);
  for(i=0;i<n;i++){
    x[i]=l+(i+1)-1;
    if(abs(x[i])<ans){
      ans=abs(x[i]);
      k=x[i];
    }
  }
  for(i=0;i<n;i++){
    if(k==x[i]){
      x[i]=0;
      break;
    }
  }
  int sum=0;
  for(i=0;i<n;i++){
    sum+=x[i];
  }
  cout << sum << endl;
  return 0;
}