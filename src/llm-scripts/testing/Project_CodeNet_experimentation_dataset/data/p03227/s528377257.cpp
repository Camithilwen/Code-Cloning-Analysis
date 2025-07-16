#include <iostream>
using namespace std;
int main(void){
    string s;
    cin>>s;
    if (s.size()%2){
        cout<<s[2]<<s[1]<<s[0];
    }
    else{
        cout<<s;
    }
    
}
