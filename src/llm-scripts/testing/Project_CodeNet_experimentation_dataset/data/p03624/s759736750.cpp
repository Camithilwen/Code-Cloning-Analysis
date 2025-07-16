#include <bits/stdc++.h>
using namespace std;
string t;
char ch;
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
cin>>t;
sort(t.begin(),t.end());
if(t.size()==1&&t[0]=='a') {
        cout << "None";
        return 0;
    }
set <char> s;
for(long long  i=0;i<t.size();i++){
    s.insert(t[i]);
}

for(char i='a';i<='z';i++){
    if(s.count(i)==true)continue;
    else{
        cout<<i;
        return 0;
    }}
cout<<"None";
return 0;}

