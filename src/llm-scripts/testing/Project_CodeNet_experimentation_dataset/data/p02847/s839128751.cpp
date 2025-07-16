#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
    string S;
    cin>>S;
    map<string,int> num;
    num["SUN"]=7;
    num["MON"]=6;
    num["TUE"]=5;
    num["WED"]=4;
    num["THU"]=3;
    num["FRI"]=2;
    num["SAT"]=1;
    
   cout<<num[S]<<endl;
}


