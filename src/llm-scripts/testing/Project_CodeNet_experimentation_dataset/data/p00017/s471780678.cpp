#include <iostream>
#include <string>
using namespace std;
int main(){
      string s;
      while(getline(cin,s)||!cin.eof()){
            for(int i=0;i<25;i++){
                  if(s.find("the")!=-1||s.find("this")!=-1||s.find("that")!=-1)break;
                  else for(int j=0;j<s.size();j++)if(s[j]>='a'&&s[j]<='z')s[j]!='z'?s[j]++:s[j]='a';
            }
            cout<<s<<endl;
      }
}