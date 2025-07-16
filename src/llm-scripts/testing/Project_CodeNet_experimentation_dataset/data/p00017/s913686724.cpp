#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    while(getline(cin, str)) {
        for(int i=0; i<25; i++) {
            if(str.find("the")!=string::npos) break;
            if(str.find("this")!=string::npos) break;
            if(str.find("that")!=string::npos) break;
            for(int i=0, l=str.length(); i<l; i++) {
                if(str[i]=='z') str[i]='a';
                else if(islower(str[i])) ++str[i];
            }
        }
        cout<<str<<'\n';
    }
    return 0;
}