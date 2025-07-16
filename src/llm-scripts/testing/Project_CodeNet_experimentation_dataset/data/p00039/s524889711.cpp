#include <iostream>
#include <string>

using namespace std;

void Solution()
{
    string str;
    
    int a;
    int b;
    int l;
    int x;
    
    char c;
    
    while (getline(cin, str)) //enter
    {
        x = 0;
        
        l = (int)str.size();
        
        for (int i = 0; i < l; i++)
        {
            c = str.at(i); //string text = "ABCDEF";
                            //char ch = text.at( 2 );
            
                 if (c == 'I') a = 1;
            else if (c == 'V') a = 5;
            else if (c == 'X') a = 10;
            else if (c == 'L') a = 50;
            else if (c == 'C') a = 100;
            else if (c == 'D') a = 500;
            else if (c == 'M') a = 1000;
            
            if (i)
            {
                if (b >= a)
                {
                    x += b;
                }
                else
                {
                    x -= b;
                }
            }
            
            b = a;
        }
        
        x += b;
        
        cout << x << endl;
    }
    
}

int main()
{
    Solution();
    return 0;
}