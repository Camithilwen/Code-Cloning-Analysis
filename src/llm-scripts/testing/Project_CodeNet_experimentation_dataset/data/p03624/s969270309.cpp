#include <bits/stdc++.h>
using namespace std;

int main(){

string s;
  cin >> s;
bool c=true;
for(int i=97;i<=122;i++){
        c=true;
for(int j=0;s[j]!='\0';j++){
        if(char(i)==s[j]){
        c=false;
        continue;
        }
}
        if(c==true){
            cout<<char(i);
            break;
        }
}
if(c==false)
        cout<<"None";
 return 0;
}