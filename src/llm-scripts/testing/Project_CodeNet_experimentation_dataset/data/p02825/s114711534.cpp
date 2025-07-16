#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define rv(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int M = 120000;
typedef long long ll;
int n,m,k;
char grid[8][10][10]={{"aa.","..a","..a"},
{"aabc","ddbc","bcaa","bcdd"},
{"aabba","bcc.a","b..cb","a..cb","abbaa"},
{
    "aabc..",
    "ddbc..",
    "..aabc",
    "..ddbc",
    "bc..aa",
    "bc..dd"
},
{
    "aabbcc.",
    "dd.dd.a",
    "..d..da",
    "..d..db",
    "dd.dd.b",
    "..d..dc",
    "..d..dc"
}};
char ans[1001][1001];
void out(int x){
    fo(i,0,x-1) {
        ans[i][x]='\0';
        printf("%s\n",ans[i]);
    }
}
void ass(int x,int y,int num){
    fo(i,0,num+2)
        fo(j,0,num+2)
            ans[i+x][j+y]=grid[num][i][j];
}
int main(){
    while(cin>>n){
        if(2==n) puts("-1");
        else {
            fo(i,0,n-1)
                fo(j,0,n-1)
                    ans[i][j]='.';
            int i;
            for(i=0;n-i*4>7;++i) {
                ass(i*4,i*4,1);
            }
            ass(i*4,i*4,n-i*4-3);
            out(n);
        }
    }
    return 0;
}