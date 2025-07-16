#include <bits/stdc++.h>
using namespace std;
int i,j,k,count1=0,count2=0;

int main(void){
    int ans=0;
    string s;
    cin>>s;
    if(s.length()%2==0){
        for(i=0;i<s.length();i+=2){
            if(s[i]=='h'&&s[i+1]=='i')count1++;
        }
    }
    if(count1==s.length()/2)ans=1;
    if(s.length()==1)ans=0;
    cout<<(ans? "Yes" : "No")<<endl;
}