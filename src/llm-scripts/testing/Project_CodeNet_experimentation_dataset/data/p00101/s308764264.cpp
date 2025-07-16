
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(void)
{
  int n;
  cin >> n;
  getchar();
  for(int i=0;i<n;i++){
    string s;
    getline(cin,s);
    for(int j=0;j<(int)s.size()-6;j++){
      string hos = s.substr(j,7);
      if(hos == "Hoshino"){
	s[j+6] = 'a';
      }
    }
    cout << s << endl;
  }
}