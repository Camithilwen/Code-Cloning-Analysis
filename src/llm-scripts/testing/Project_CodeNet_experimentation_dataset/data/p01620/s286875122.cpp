#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

void Solve(int n){
  std::vector<int> key(n);
  for(int i=0;i<n;i++){
    cin>>key[i];
  }
  std::string s;
  cin>>s;
  std::string result;
  int key_itr=0;
  for(int i=0;i<s.size();i++){
    char target=s[i];
    for(int i=0;i<key[key_itr];i++){
      target--;
      if(target<'A'){
        target='z';
      }
      else if('Z'<target&&target<'a'){
        target='Z';
      }
    }
    result+=target;
    key_itr++;
    if(key_itr>=n){
      key_itr=0;
    }
  }
  cout<<result<<endl;
}

int main(void) {
  cout << std::fixed << std::setprecision(10);
  cin.tie(0);
  std::ios::sync_with_stdio(false);

  while(1){
    int n;
    cin>>n;
    if(n==0){
      return 0;
    }else{
      Solve(n);
    }
  }


  return 0;
}

