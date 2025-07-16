#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>

#define INF (2 << 28)
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> iP;

typedef pair<double, double> dP;

int main(){
  
  string line;
  int l[10];
  
  while(~scanf("%d,", l)){
    int v1, v2;
    vector <dP> t1(10);
    vector <dP> t2(10);
    int l1[10] = {}, l2[10] = {};
    
    for(int i = 1; i < 10; i++) 
      scanf("%d,", l + i);
    scanf("%d,%d", &v1, &v2);
    
    l1[0] = l[0], l2[9] = l[9];
    for(int i = 1; i < 10; i++){
      l1[i] += l1[i - 1] + l[i];
      l2[9 - i] += l2[9 - i + 1] + l[9 - i];
    }
     
    double begin = 0;
    for(int i = 0; i < 10; i++){
      t1[i].fr = begin;
      t1[i].sc = (double)l1[i] / v1;
      begin = (double)l1[i] / v1;
    }

    begin = 0;
    for(int i = 9; i >= 0; i--){
      t2[i].fr = begin;
      t2[i].sc = (double)l2[i] / v2;
      begin = (double)l2[i] / v2;
    }

    for(int i = 0; i < 10; i++){
      if(!(t1[i].fr > t2[i].sc || t2[i].fr > t1[i].sc)){
        cout << i + 1 << endl;
        break;
      }
    }
  }
}