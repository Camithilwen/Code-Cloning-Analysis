#include <bits/stdc++.h>
 
using namespace std;
 
//const int MOD=1e9+7;
 
const int MOD=998244353;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    
    if(!(n%3)){
        vector<string> ans(n,string(n,'.'));
        
        for(int i=0; i<n; i+=3){
            ans[i][i]='a';
            ans[i][i+1]='a';
            ans[i+1][i+2]='a';
            ans[i+2][i+2]='a';
        }
        for(auto s:ans){
            cout<<s<<'\n';
        }
        return 0;
    }
    if(!(n%4)){
        vector<string> vs={"aacd","bbcd","cdaa","cdbb"};
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j+=4){
                cout<<vs[i%4];
            }
            cout<<'\n';
        }
        return 0;
    }
    if(!(n%5)){
        vector<string> vs={"xyycc","xaa.w","i..aw","i..au","ssttu"};
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j+=5){
                cout<<vs[i%5];
            }
            cout<<'\n';
        }
        return 0;
    }
    int a=-1,b=-1;
    
    for(int i=0; i<1000 && a==-1; i++){
        for(int j=0; j<1000; j++){
            if(5*i+4*j==n){
                a=i;
                b=j;
                break;
            }
        }
    }
    
    if(a!=-1){
        //cout<<a<<' ';
        vector<string> vs4={"aacd","bbcd","cdaa","cdbb"};
        vector<string> vs5={"xyycc","xaa.w","i..aw","i..au","ssttu"};
        vector<string> ans(n,string(n,'.'));
        int pos=0;
        
        while(pos<b*4){
            for(int i=0; i<4; i++){
                for(int j=0; j<4; j++){
                    ans[pos+i][pos+j]=vs4[i%4][j];
                }
            }
            pos+=4;
        }
        while(pos<b*4+a*5){
            for(int i=0; i<5; i++){
                for(int j=0; j<5; j++){
                    ans[pos+i][pos+j]=vs5[i%5][j];
                }
            }
            pos+=5;
        }
        
        
        for(auto s:ans){
            cout<<s<<'\n';
        }
        return 0;
        
    }
    for(int i=0; i<1000 && a==-1; i++){
        for(int j=0; j<1000; j++){
            if(7*i+4*j==n){
                a=i;
                b=j;
                break;
            }
        }
    }
    
    if(a!=-1){
        //cout<<a<<' ';
        vector<string> vs7={"abb...x","a.c...x","ddc...y","...abby","...a.cz","...ddcz","xxyyzz."};
        vector<string> vs4={"aacd","bbcd","cdaa","cdbb"};
        vector<string> ans(n,string(n,'.'));
        int pos=0;
        
        while(pos<b*4){
            for(int i=0; i<4; i++){
                for(int j=0; j<4; j++){
                    ans[pos+i][pos+j]=vs4[i%4][j];
                }
            }
            pos+=4;
        }
        while(pos<b*4+a*7){
            for(int i=0; i<7; i++){
                for(int j=0; j<7; j++){
                    ans[pos+i][pos+j]=vs7[i%7][j];
                }
            }
            pos+=7;
        }
        
        
        for(auto s:ans){
            cout<<s<<'\n';
        }
        return 0;
        
    }
    
    
    
    cout<<-1;
    
    
    return 0;
}
