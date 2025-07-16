#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[1500];
    int i,n;
    cin>>s;
    n=strlen(s);
    if(n==2){
        cout<<s;
    }
    else{
        for(i=n-1;i>=0;i--){
            cout<<s[i];
        }
    }
return 0;


    }

