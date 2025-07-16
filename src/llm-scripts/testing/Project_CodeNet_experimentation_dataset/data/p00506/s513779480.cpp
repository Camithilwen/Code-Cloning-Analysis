#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctype.h>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define lengthof(x) (sizeof(x) / sizeof(*(x)))
#define FILL(ptr, value) FILL_((ptr), sizeof(ptr)/sizeof(value), (value))
template <typename T>
void FILL_(void * ptr, size_t size, T value){
  std::fill((T*)ptr, (T*)ptr+size, value);
}
//4方向ベクトル→↑←↓
int dx[] ={1,0,-1,0};
int dy[] ={0,-1,0,1};
int A[3];
unsigned int use[100000001];
priority_queue<int,vector<int>,greater<int> > ans;
int main()
{
  int n;
  cin >>n;
  int Min = 1e+9;
  for(int i = 0;i < n;i++){
    cin >>A[i];
    if(Min >A[i]){
      Min = A[i];
    }
  }
    if(n ==2){
      for(int i = 1;i <=Min;i++){
	  if(A[0]%i==0&&use[i]!=1&&A[1]%i==0){
	    use[i] = 1;
	    ans.push(i);
	}
      }
    }
      if(n == 3){
	for(int i = 1;i <=Min;i++){
	    if(A[0]%i==0&&use[i]!=1&&A[1]%i==0&&A[2]%i==0){
	      use[i] = 1;
	      ans.push(i);
	    }
	}
      }
      while(!ans.empty()){
	cout <<ans.top()<<endl;
	ans.pop();
      }
  return 0;
}