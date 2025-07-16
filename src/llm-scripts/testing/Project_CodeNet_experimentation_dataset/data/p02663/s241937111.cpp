#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    string times;
    int x=0;
    int n;
    vector <int> number;
getline(cin,times);
stringstream s(times);
while(s>>n)
    number.push_back(n);

x=(60*(number[2]-number[0])+(number[3]-number[1]))-number[4];

    cout<<x<<endl;


    return 0;
}
