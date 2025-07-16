#include <iostream>
using namespace std;

int main()
{
  string test;
  getline(cin,test);

  if (test[0] == 'A' && test[1] == 'C')
  {
    cout << "Yes" << endl;
  }
  else if(test[1] == 'A' && test[2] == 'C')
  {
    cout << "Yes" << endl;
  }
  else if(test[2] == 'A' && test[3] == 'C')
  {
    cout << "Yes" << endl;
  }
  else if(test[3] == 'A' && test[4] == 'C')
  {
    cout << "Yes" << endl;
  }
  else
  cout << "No" << endl;
}
