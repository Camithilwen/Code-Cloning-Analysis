#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << #x << " = " << x << endl;


#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 100010

bool solve(){
  int n;
  int k[SIZE];
  char c[SIZE];
  
  scanf("%d",&n);
  
  if(n == 0) return false;

  for(int i=0;i<n;i++){
    scanf("%d",k+i);
  }

  scanf("%s",c);
  
  for(int i=0;c[i]!='\0';i++){

    for(int j=0;j<k[i%n];j++){
      if(c[i] == 'a')
        c[i] = 'Z';
      else if(c[i] == 'A')
        c[i] = 'z';
      else
        c[i]--;
    }
    
  }

  printf("%s\n",c);
  
  return true;

}

int main(){

  while(solve());
  
  return 0;
}