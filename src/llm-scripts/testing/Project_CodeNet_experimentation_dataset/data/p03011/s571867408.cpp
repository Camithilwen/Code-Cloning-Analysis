#include<bits/stdc++.h>
//#include<atcoder/all>

using namespace std;
//using namespace atcoder;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<a+b+c-max(a,max(b,c))<<endl;
}
