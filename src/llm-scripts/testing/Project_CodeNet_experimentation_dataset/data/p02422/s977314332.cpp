#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
  string str;
  string pri;
  string rev;
  string p;
  string oreder;
  int q;
  int i;
  int a;
  int b;
  int j;
  int k;
  
  cin >> str >> q;
  
  for(k=0;k<q;k++)
  {
    cin >> oreder;
    if(oreder=="print")
    {
      cin >> a >> b;
      
      pri=str.substr(a,(b-a+1));
      
      cout << pri <<"\n";
      continue;
    }
    
    if(oreder=="reverse")
    {
      cin >> a >> b;
      rev=str.substr(a,(b-a+1));
      for(i=a,j=(b-a);i<=b;i++,j--)
      {
        str[i]=rev[j];
      }
      continue;
    }
    
    if(oreder=="replace")
    {
      cin >> a >> b >> p;
      
      for(i=a,j=0;i<=b;i++,j++)
      {
        str[i]=p[j];
      }
      continue;
    }
    
  }
}