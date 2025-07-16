#include<iostream>
#include<string>
using namespace std;
int main(){
  int n;
  cin >>n;
  cin.ignore();
  while(n--){
    string word;
    getline(cin,word);
    string::size_type index;
    for(;;){
      index = word.find("Hoshino");
      if(index == string::npos){break;}
      word[index+6] = 'a';
    }
    cout <<word<<endl;
  }
  return 0;
}