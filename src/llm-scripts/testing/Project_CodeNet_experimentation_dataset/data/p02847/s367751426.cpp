#include<iostream>
#include<string>
using namespace std;
int main(){
  string s;
  cin >> s;
  if(s == "SUN"){
    cout << "7\n";
    return 0;
  }
  if(s == "MON"){
    cout << "6\n";
    return 0;
  }
  if(s == "TUE"){
    cout << "5\n";
    return 0;
  }
  if(s == "WED"){
    cout << "4\n";
    return 0;
  }
  if(s == "THU"){
    cout << "3\n";
    return 0;
  }
  if(s == "FRI"){
    cout << "2\n";
    return 0;
  }
  if(s == "SAT"){
    cout << "1\n";
    return 0;
  }
}