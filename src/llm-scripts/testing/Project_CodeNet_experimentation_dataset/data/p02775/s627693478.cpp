#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n,flag=0,result=0;
    cin>>s;
    for(long int i=s.size()-1;i>=0;i--){
        n=s[i]-'0'+flag;
        if(n<(10-n) || (n==5 && s[i-1]<'5')){
            flag=0;
            result+=n;
        }
        else{
            flag=1;
            result+=(10-n);
        }
    }
    result+=flag;
    cout<<result;
}

