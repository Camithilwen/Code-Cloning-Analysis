#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>

using namespace std;
const int dx[] = {1,0,-1,0},dy[] = {0,1,0,-1};
#define INF 999999
#define rep(i,j) for(int i=0;i<(j);i++)
#define reps(i,j,k) for(int i=j;i<k;i++)
typedef long long ll;
typedef unsigned long long ull;
int check(char str);
int counter(int res,char *str);
int main(){
    char str[128]={0};
    while(~scanf("%s",str)){

        /*宣言*/
        int ans = 0,bef = 0;
        int cnt = 1;
        int len = strlen(str);
        int x;
        bool f = false;
        /*宣言終了*/

        reverse(str,str+len);
        rep(i,len){
            x = check(str[i]);
            if(!f){
                bef = x;
                f = true;
                continue;
                cnt++;
            }
            if(bef == x){
                cnt++;
            }
            else if(bef < x){
                ans += cnt*bef;
                cnt = 1;
                bef = x;
            }
            else{
                int coun = counter(i,str);
                ans += (bef*cnt) - (coun*x);
                cnt = 1;
                f = false;
                i += coun-1;
            }
        }
        if(x == bef)ans += cnt*bef;
        printf("%d\n",ans);
    }
	return 0;
}
int check(char str){
    if(str == 'I')return 1;
    if(str == 'V')return 5;
    if(str == 'X')return 10;
    if(str == 'L')return 50;
    if(str == 'C')return 100;
    if(str == 'D')return 500;
    if(str == 'M')return 1000;
}
int counter(int res , char *str){
    int cnt = 1;
    for(int i = res; str[i] != str[res] ; i++){
        cnt++;
    }
    return cnt;
}