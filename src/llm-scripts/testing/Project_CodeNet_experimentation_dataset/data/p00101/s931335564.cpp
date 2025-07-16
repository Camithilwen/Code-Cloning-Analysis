#include <iostream>
#include <cstring>
#include <string>
 
using namespace std;
 
int main(){
    string s;
    int n;
    int c_pos;
    cin>>n;
    cin.ignore();
    while(n--){
        getline(cin,s);
        while((c_pos=s.find("Hoshino"))!=string::npos){
            s.replace(c_pos,7,"Hoshina");
        }
        cout<<s<<endl;
    }
}