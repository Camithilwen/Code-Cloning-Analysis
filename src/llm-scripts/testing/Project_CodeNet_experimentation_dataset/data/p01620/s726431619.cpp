#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<bitset>
#include<functional>
#include<climits>
using namespace std;
typedef pair<int,int>pii;
const int INF=1e9;
const int dx[]={0,-1,0,1},dy[]={-1,0,1,0};


int main(){
    int n;
    while(cin>>n,n){
        int a[100];for(int i=0;i<n;i++)cin>>a[i];
        char str[128];cin>>str;
        for(int i=0;str[i];i++){
            int val=(isupper(str[i])?tolower(str[i])-'a'+26:str[i]-'a');
            int next=val-a[i%n];
            next=(next+52)%52;
            if(next>25)next=toupper('a'+next-26)-'a';
            printf("%c",'a'+next);
        }
        puts("");
    }
    return 0;
}