#include <iostream>
#include <string>
using namespace std;

int main()
{
  string N;
  cin >> N;
  
  if(N[0] == '7' || N[1] == '7' || N[2] == '7')
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}