#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    string s;
    cin>>s;
    bool f=true;
    long long ans=0;
    if(s[0]!='A'){
        f=false;
    }
    f(i,2,s.size()-1){
        if(s[i]=='C'){
            ans++;
        }
        else if(s[i]-'a'<0){
            f=false;
        }
    }
    if(s[1]-'a'<0||s[s.size()-1]-'a'<0){
        f=false;
    }
    if(f&&ans==1){
        cout<<"AC"<<endl;
    }
    else{
        cout<<"WA"<<endl;
    }
    return 0;
}
