#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a;
    string str,Hoshino="Hoshino";
    cin>>n;
    getline(cin,str);
    for(int i=0;i<n;i++){
        getline(cin,str);
        for(int j=0;str[j]!='\0';j++){
            if(str[j]=='H'){
                for(int k=j;k<7+j;k++){
                    if(str[k]!=Hoshino[k-j])break;
                    if(k==j+6)str[k]='a';
                }
            }
        }
        cout<<str<<endl;
    }
}