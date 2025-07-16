#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    int num,rest=0,result=0;
    cin>>str;
    for(long int i=str.size()-1;i>=0;i--){
        num=str[i]-'0'+rest;
        if(num<(10-num) || (num==5 && str[i-1]<'5')){
            rest=0;
            result+=num;
        }
        else{
            rest=1;
            result+=(10-num);
        }
    }
    result+=rest;
    cout<<result;
}


