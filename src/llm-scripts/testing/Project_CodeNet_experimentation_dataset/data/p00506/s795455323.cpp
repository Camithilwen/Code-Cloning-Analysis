#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f

#include <iostream>
#include <cstdio>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits>
#include <map>
#include <string>
#include <cstring>
#include <set>
#include <deque>
#include <bitset>
#include <list>
#include <cctype>
#include <utility>
  
using namespace std;
  
typedef long long ll;
typedef pair <int,int> P;
typedef pair <int,P> PP;
  
static const double EPS = 1e-8;
  
static const int tx[] = {0,1,0,-1};
static const int ty[] = {-1,0,1,0};

int main(){
  int n;
  while(~scanf("%d",&n)){
    map<int,int> freq;
    for(int i=0;i<n;i++){
      int num;
      scanf("%d",&num);
      for(int div=1;div*div<=num;div++){
	if(num % div == 0){
	  freq[div]++;
	  if(div != (num/div)) freq[num/div]++;
	}
      }
    }
    for(map<int,int>::iterator it = freq.begin();
	it != freq.end();
	it++){
      if(it->second >= n){
	printf("%d\n",it->first);
      }
    }
  }
}