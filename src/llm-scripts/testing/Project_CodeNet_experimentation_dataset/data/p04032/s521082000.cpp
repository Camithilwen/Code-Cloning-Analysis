#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    getline(cin,a);
    if(a.size()==2 && a[0]==a[1]){
        cout<<"1 2"<<endl;
        return 0;
    }
    long long i,flag=0;
    for(i=0;i<a.size()-2;i++)
    {
        if(a[i]==a[i+1] || a[i]==a[i+2] || a[i+1]==a[i+2]){
            cout<<i+1<<" "<<i+3<<endl;
            flag=1;
            break;
        }

    }
    if(!flag)
        cout<<"-1 -1"<<endl;
}
