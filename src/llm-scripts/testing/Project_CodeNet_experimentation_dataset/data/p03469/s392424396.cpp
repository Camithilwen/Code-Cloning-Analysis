#include <iostream>
using namespace std;
int main()
{
    string date;
    getline(cin,date);
    string date2;
    date2=date.substr(4,6);
    cout << "2018"<< date2;
	
}
