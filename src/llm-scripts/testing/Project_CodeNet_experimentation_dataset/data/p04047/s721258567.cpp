#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
  int N;
  cin >> N;
  N *= 2;
  int L[N];
  for (int i = 0; i < N; i++) cin >> L[i];
  
  int count = 0;
  
  priority_queue<int> Que;
  for (int i = 0; i < N; i++){
    Que.push(L[i]);
  }
  
  while(!Que.empty()){
    Que.pop();
    if (Que.empty()) break;
    count += Que.top();
    Que.pop();
  }
  
  cout << count << endl;
}