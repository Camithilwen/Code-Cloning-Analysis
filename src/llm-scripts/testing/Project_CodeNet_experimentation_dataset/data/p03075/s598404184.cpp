#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector<int> abcde(5);
  int k;
  for(int i = 0;i < 5;i++) cin >> abcde.at(i);
  cin >> k;
  
  for(int i = 0;i < 5;i++){
    for(int j = i + 1;j < 5;j++){
      if(k < abcde.at(j) - abcde.at(i)){
        cout << ":(" << endl;
        return 0;
      }
    }
  }
  cout << "Yay!" << endl;
  
  return 0;
}