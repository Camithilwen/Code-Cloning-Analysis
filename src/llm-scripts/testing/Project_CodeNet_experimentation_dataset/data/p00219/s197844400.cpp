#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    while(1)
    {
        int sell_num[10] = {};
        cin >> n;
        if(n == 0)
        {
            break;
        }
        for(int i=0; i<n; i++)
        {
            int id;
            cin >> id;
            sell_num[id]++;
        }
        for(int i=0; i<10; i++)
        {
            if(sell_num[i] == 0)
            {
                cout << "-" << endl;
            }
            else
            {
                string str;
                for(int j=0; j<sell_num[i]; j++)
                {
                    str += "*";
                }
                cout << str << endl;
            }
        }
    }
    return 0;
}