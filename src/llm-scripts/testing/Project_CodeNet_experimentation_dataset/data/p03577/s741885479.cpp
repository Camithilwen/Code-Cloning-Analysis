#include <iostream>
using namespace std;

int main()
{
  string name;
  int count = 0;
  getline(cin,name);

  /*if (name == "FESTIVAL")
  {
    cout << "Yes" << endl;
  }*/

  if(name[name.length()-1] == 'L')
  {
    for(int i = 0; i < name.length()-8; i++)
    {
      cout << name[i];
    }
  }
  cout << endl;
}
