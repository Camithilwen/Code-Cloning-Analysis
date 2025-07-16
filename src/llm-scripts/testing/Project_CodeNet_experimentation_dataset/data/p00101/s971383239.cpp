#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

int main()
{
    int n;
    cin>>n;
    getchar();
    while(n!=0){
        string str;
        getline(cin,str);
        for(int i=0;i<str.length();i++){
            if(str[i]=='H' && str[i+1]=='o' && str[i+2]=='s' && str[i+3]=='h' && str[i+4]=='i' && str[i+5]=='n' && str[i+6]=='o'){
                str[i+6]='a';
                i += 6;
            }
        }
        cout<<str<<endl;
        n--;
    }
    return 0;
}