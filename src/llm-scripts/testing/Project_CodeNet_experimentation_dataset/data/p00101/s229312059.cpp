#include <iostream>
#include <string>
using namespace std;
int main() 
{
    string tmp;
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        getline(cin,tmp);
        while (tmp=="") getline(cin,tmp);
        while (tmp.find("Hoshino")!=string::npos) {
            tmp.replace(tmp.find("Hoshino"),7,"Hoshina");
        }
        cout<<tmp<<endl;
    }
}