#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>

using namespace std;
int main()
{
    int n;
    string str;
    cin >> n;
    cin.get();
    for(int i=0;i<n;++i)
    {
        int loc;
        getline(cin, str);
        loc = str.find("Hoshino",0);
        while(loc!=string::npos)
        {
            str[loc+6] = 'a';
            loc = str.find("Hoshino",0);
        }
        cout << str << endl;
    }
}