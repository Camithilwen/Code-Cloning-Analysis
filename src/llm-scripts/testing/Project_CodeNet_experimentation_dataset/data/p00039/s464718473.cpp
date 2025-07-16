#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

#define loop(i,a,b) for(int i=(a); i<(int)(b); i++)
#define rep(i,n) loop(i,0,n)

int main(void){
    string ro;
    int m[256]={};
    m['I']=1,
        m['V']=5,
        m['X']=10,
        m['L']=50,
        m['C']=100,
        m['D']=500,
        m['M']=1000;
    while(cin>>ro){
        int n=0;
        for(auto c:ro)n+=m[c];
        rep(i,ro.size()) if(m[ro[i]]<m[ro[i+1]])n-=2*m[ro[i]];
        cout<<n<<endl;
    }
}