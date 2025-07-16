#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector<int> outp;
  int icn;
  int icd;
  int g;
  vector<int> ice;
  for(g = 0;;g++){
    vector<int> ice(10,0);
    cin >> icn;
    if(icn == 0){
      break;
    }else{
    for(int a = 0;a< icn;a++){
      cin >> icd;
      ice[icd] += 1;
    }
    outp.insert(outp.end(),ice.begin(),ice.end());
  }
  }
  for(int n = 0;n<g * 10;n++){
    if(outp[n] == 0){
      cout << "-";
    }else{
      for(int c = 0;c<outp[n];c++){
        cout << "*" ;
      }
    }
    cout << endl;
  }
  return 0;
}