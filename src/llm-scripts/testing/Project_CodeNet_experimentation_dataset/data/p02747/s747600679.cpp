#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string s;
    cin >> s;
    if (s.length() % 2 == 1)
    {
        cout << "No" << endl;
    }
    else
    {
        for (int i = 0; i < (int)s.length(); i += 2)
        {
            if (s[i] != 'h' || s[i + 1] != 'i')
            {
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
    }
    return 0;
}
