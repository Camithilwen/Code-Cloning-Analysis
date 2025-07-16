#include <iostream>
#include <cctype>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <complex>
#include <cstring>
#include <set>
using namespace std;
#define loop(i,a,b) for(int i=a; i<b; i++)
#define rep(i,a) loop(i,0,a)

int input[1111][3], res[1111];

int main(){
    int a,b,c;
    while(cin>>a>>b>>c && a){
        int n; cin>>n;
        rep(i,n){
            rep(j,3)cin >> input[i][j];
            cin>>res[i];
        }

        bool ok[1111]={}, bad[1111]={};
        rep(k,2){
            rep(i,n){
                int a=0,b=0;
                int x,y,z;
                tie(x,y,z)=tie(input[i][0],input[i][1],input[i][2]);
                for(int j : {x,y,z}){
                    if(ok[j])a++;
                    if(bad[j])b++;
                }
                if(res[i]){
                    if(a!=3){
                        ok[x]=ok[y]=ok[z]=true;
                    }
                }else{
                    if(a==2 && b!=1){
                        for(int j : {x,y,z}){
                            if(!ok[j])bad[j]=true;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=a+b+c;i++){
            if(ok[i] && !bad[i])cout<<1;
            else if(!ok[i] && bad[i])cout<<0;
            else cout<<2;
            cout<<endl;
        }
    }
}