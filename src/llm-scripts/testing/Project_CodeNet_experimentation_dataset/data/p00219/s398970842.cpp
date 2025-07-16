#include<bits/stdc++.h>
#define endl '\n'
#define INF (1 << 21)
const int MOD = 1000000009;
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  int ice[10];
  int c;

  cin >> n;
  while(n != 0){
    memset(ice, 0, sizeof(ice));
    for(int i = 0;i < n;i++){
      cin >> c;
      ice[c]++;
    }
    
    for(int i = 0;i <= 9;i++){
      if(ice[i] == 0){
	cout << "-" << endl;
      }else{
	for(int j = 0;j < ice[i];j++){
	  cout << "*";
	}
	cout << endl;
      }
    }
    
    cin >> n;
  }
  return 0;
}


