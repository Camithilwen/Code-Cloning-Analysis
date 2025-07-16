#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P =pair<int,int>;

int main(){
    string S;
    cin>>S;
    rep(i,S.size()-1){
        if(S.at(i)=='A'){
            if(S.at(i+1)=='C'){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
return 0;}
/*compile
g++ code.cpp
./a.out
run*/
/*
int f(int x){
    int y=int((x*x+4.0)/8.0);
    return y;
}
*/