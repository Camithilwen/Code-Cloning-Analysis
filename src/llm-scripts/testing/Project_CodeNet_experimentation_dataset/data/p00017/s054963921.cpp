#include <iostream>
#include <string>

using namespace std;

int main()
{
  string stro, str;
  while(getline(cin, stro)){
    for(int i = 0; i < 26; i++){
      str = stro;
      for(int j = 0; j < stro.length(); j++){
	if(str[j] >= 'a' && str[j] <= 'z')
	  if(str[j] + i > 'z')
	    str[j] += i - 26;
	  else
	    str[j] += i;
      }
      if(str.find("the") != string::npos || str.find("this") != string::npos || str.find("that") != string::npos)
	cout << str << endl;
    }
  }
}