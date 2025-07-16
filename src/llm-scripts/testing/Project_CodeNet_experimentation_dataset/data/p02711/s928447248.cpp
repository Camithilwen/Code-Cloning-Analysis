#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    char s[4];
    cin >> ("%s",s);
    if(s[0]=='7'||s[1]=='7'||s[2]=='7')
    cout << ("Yes");
    else
    cout << ("No");
}
