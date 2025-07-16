#include <iostream>
#include <string>
using namespace std;

char byte_minus(char ch, int num)
{
  if ( 97 <= ch && ch <= 122 )
  {
    if ( ch - 97 >= num )
    {
      return ch - num;
    }
    else
    {
      return byte_minus('Z', num - (ch - 96) );
    }
  }
  else
  {
    if ( ch - 65 >= num )
    {
      return ch - num;
    }
    else
    {
      return byte_minus('z', num - (ch - 64) );
    }
  }
}

int main()
{
  while (true)
  {
    int n;
    cin >> n;
    if ( n == 0 ) break;
    int* keys = new int[n];
    for (int i = 0; i < n; i++)
    {
      cin >> keys[i];
    }
    string cipher;
    //getline(cin, cipher);
    cin >> cipher;
    for (int i = 0, size = cipher.length(); i < size; i++)
    {
      int key_index = i % n;
      char result = byte_minus(cipher[i], keys[key_index]);
      cout << result;
    }
    cout << endl;
  }
  return 0;
}