#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long member[4000];
bool ached[4000];
vector<int> ach;

int main(void){
  int n;
  while(true){
    cin >> n;
    if(n == 0)  break;
    fill(member, member + 4000, 0);
    fill(ached, ached + 4000, false);
    ach.clear();
    for(int i = 0; i < n; i++){
      long long id, tanka, suryo;
      cin >> id >> tanka >> suryo;
      member[id] += tanka * suryo;
      if(member[id] >= 1000000 && ached[id] == false){
        ach.push_back(id);
        ached[id] = true;
      }
    }

    if(ach.empty()){
      cout << "NA" << endl;
    }else{
      for(int i = 0; i < ach.size(); i++){
        cout << ach[i] << endl;
      }
    }
  }
  return 0;
}