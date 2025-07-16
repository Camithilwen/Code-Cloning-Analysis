#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N;
  cin >> N;
  vector<int> num(4);
  for(int i=0;i<4;i++){
    num[3-i]=N%10;
    N/=10;
  }
  for(int i=0;i<(1<<3);i++){
    vector<char> op(3);
    int ans=num[0];
    for(int j=0;j<3;j++){
      if((i & (1<<j))==(1<<j)){
        ans+=num[j+1];
        op[j]='+';
      }
      else{
        ans-=num[j+1];
        op[j]='-';
      }
    }
    if(ans==7){
      for(int i=0;i<4;i++){
        cout << num[i];
        if(i!=3){
          cout << op[i];
        }
      }
      cout << "=7" << endl;
      return 0;
    }
  }
}