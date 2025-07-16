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
  int i,k,x;
  cin >> k >> x;
  for(i=x-k+1;i<=k+x-1;i++){
    if(i==x-k+1){
      printf("%d",i);
    }
    else{
      printf(" %d",i);
    }
  }
  printf("\n");
  return 0;
}