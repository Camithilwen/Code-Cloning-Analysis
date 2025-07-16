#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
using namespace std;

int main(){
  long long N;
  cin >> N;
  vector<long long> a(N+1,0);
  for(int i = 1;i < N + 1;i++){
    cin >> a.at(i);
  }
  vector<bool> b(N + 1,false);
  long long M = 0;
  for(long long i = N;i >= 1;i--){
    long long c = 0;
    for(long long j = 2*i;j <= N;j+= i){
      c += b.at(j);
    }
    b.at(i) = (c % 2 != a.at(i));
    M += b.at(i);
  }
  cout << M << endl;
  for(int i = 1;i < N + 1;i++){
    if(b.at(i)){
      cout << i << " ";
    }
  }
  cout << endl;
}

/*
int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  vector<int> b(N+1);
  for(int i = 0;i < N;i++){
    cin >> a.at(i);
    b.at(i) = 0;
  }
  b.at(N+1) = 0;
  int M = 0;
  /*for(int i = N - 1;i >= 0;i--){
    int count = 0;
    for(int j = i;j < N;j++){
      count += b.at(j);
    }
    if(count%2 != a.at(i)){
      b.at(i) = abs(a.at(i) - count);
      M ++;
    }
  }
  for(int i = N - 1;i >= 0;i--){
    int count = 0;
    for(int j = 2*i;j <= N;j+=i){
      count += b.at(j);
    }
    if(count%2 != a.at(i)){
      b.at(i) = abs(a.at(i) - count);
      M ++;
    }
  }
  cout << M << endl;
  if(M != 0){
  for(int i = 0;i < N;i++){
    if(b.at(i) != 0){
      cout << i + 1 << " ";
    }
  }
  cout << endl;
}
}
*/
