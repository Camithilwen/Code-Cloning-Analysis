#include <iostream>
#include <sstream>
#include <string>

using namespace std;

constexpr int n = 10;
int L[n+2],P[n];
int main(){
  string str;
  while(getline(cin,str)){
    string tmp;
    istringstream stream(str);
    for(int i=0;getline(stream,tmp,',');++i){
      L[i] = stod(tmp);
    }
    P[0] = L[0];
    for(int i=1;i<n;++i) P[i] = P[i-1] + L[i];
    int v1 = L[n],v2 = L[n+1];

    double p = (double)P[n-1]/(v1+v2)*v1;
    
    for(int i=0;i<n;++i){
      if(p<=P[i]){
        cout << i+1 << endl;
        break;
      }
    }

  }
}