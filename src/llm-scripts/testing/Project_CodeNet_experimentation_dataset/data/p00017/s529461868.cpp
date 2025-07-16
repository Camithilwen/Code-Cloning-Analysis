#include<iostream>
#include<string>
using namespace std;

int main(void){
    string str;
    while(getline(cin, str)){
        for(int i=0; i<26; i++){
            for(int j=0; j<str.size(); j++){
                if(str[j]!=' ' && str[j]!='.'){
                    str[j]++;
                    if(str[j]>'z') str[j]-=26;
                }
            }
            if(str.find("the")!=string::npos){
                cout<<str<<endl;
                break;
            }else if(str.find("this")!=string::npos){
                cout<<str<<endl;
                break;
            }else if(str.find("that")!=string::npos){
                cout<<str<<endl;
                break;
            }
        }
    }
}
