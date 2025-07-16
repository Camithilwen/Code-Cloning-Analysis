#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
#define int long long
map<char, int> m={
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000},
};
signed main(){
        char buf[256];
        while( scanf("%s", buf) != EOF ){
                int ans = 0;
                for(int i=0; i<256 && buf[i]!=0;i++){
                        if(buf[i+1]==0){
                                ans+=m[buf[i]];
                        }else{
                                if(m[buf[i]]<m[buf[i+1]]) ans-=m[buf[i]];
                                else ans+=m[buf[i]];
                        }
                }
                cout << ans<< endl;
        }
        return 0;
}