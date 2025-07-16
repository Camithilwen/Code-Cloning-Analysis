#include <iostream>
using namespace std;

int main(){
  int t[110]={};
  int N;
  cin >> N;
  int a,b,c,d;
  //得点
  for(int i = 0; i < N*(N-1)/2; i++){
    cin >> a >> b >> c >> d;
    if(c > d) t[a-1] += 3;
    else if(c < d) t[b-1] += 3;
    else if(c == d){
      t[a-1]++;
      t[b-1]++;
    }
  }
  //順位
  int p = 0,rank[110]={};
  for(int j = 1; j < N+1; j+=p){
    int max = -1;
    for(int i = 0; i < N; i++){
      if(max < t[i]){
	max = t[i];
      }
    } 
    p = 0;
    for(int i = 0; i < N; i++){
      if(max == t[i]){
	rank[i] = j;
	p++;
	t[i] = -1;
      }
    }
    
  }
  for(int i = 0; i < N; i++){
    cout << rank[i] << endl;
  }
  return 0;
}