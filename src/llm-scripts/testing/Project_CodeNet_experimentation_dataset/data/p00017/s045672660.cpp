#include <iostream>
#include <string>

using namespace std;

int main(){
  string text;
  while(getline(cin,text,'\n')){
    for(int i=0;i<26;i++){
      for(int w=0;w<text.size();w++){
	if ('a'<=text[w]&&text[w]<'z')
	  text[w]++;
	else if(text[w]=='z')
	  text[w] = 'a';
      }
      if (text.find("this") != string::npos||text.find("that") != string::npos||text.find("the") != string::npos){
	cout << text << endl;
	break;
      }
    }
  }
}