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
      std::string::size_type f_the = str.find("the", 0);
      std::string::size_type f_this = str.find("this", 0);
      std::string::size_type f_that = str.find("that", 0);
      if((f_the != string::npos && f_the == 0 && (str[f_the + 3] == ' ' || str[f_the + 3] == '.' || str[f_the + 3] == '\0')) || (f_this != string::npos && f_this == 0 && (str[f_this + 4] == ' ' || str[f_this + 4] == '.' || str[f_this + 4] == '\0')) || (f_that != string::npos && f_that == 0 && (str[f_that + 4] == ' ' || str[f_that + 4] == '.' || str[f_that + 4] == '\0')))
	cout << str << endl;
      else if((f_the != string::npos && (str[(f_the - 1 < 0) ? 0 : f_the - 1] == ' ' || str[(f_the - 1 < 0) ? 0 : f_the - 1] == '.' || str[(f_the - 1 < 0) ? 0 : f_the - 1] == '\n') && (str[f_the + 3] == ' ' || str[f_the + 3] == '.' || str[f_the + 3] == '\0')) || (f_this != string::npos && (str[(f_this - 1 < 0) ? 0 : f_this - 1] == ' ' || str[(f_this - 1 < 0) ? 0 : f_this - 1] == '.' || str[(f_this - 1 < 0) ? 0 : f_this - 1] == '\n') && (str[f_this + 4] == ' ' || str[f_this + 4] == '.' || str[f_this + 4] == '\0')) || (f_that != string::npos && (str[(f_that - 1 < 0) ? 0 : f_that - 1] == ' ' || str[(f_that - 1 < 0) ? 0 : f_that - 1] == '.' || str[(f_that - 1 < 0) ? 0 : f_that - 1] == '\n') && (str[f_that + 4] == ' ' || str[f_that + 4] == '.' || str[f_that + 4] == '\0')))
	cout << str << endl;	 
    }
  }
}