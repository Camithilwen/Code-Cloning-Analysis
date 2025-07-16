#include <bits/stdc++.h>
using namespace std;
char s[101];
int main() {
    int n;
    while(scanf("%d",&n),n) {
        vector<int> key;
        for(int i=0;i<n;i++) {
            int k;
            scanf("%d",&k);
            key.push_back(k);
        }
       scanf("%s",s);
       for(int i=0;s[i]!='\0';i++) {
            int code=0;
            if('a'<=s[i]&&s[i]<='z') code=s[i]-'a';
            if('A'<=s[i]&&s[i]<='Z') code=26+s[i]-'A';
            code-=key[i%key.size()];
            while(code<0) code+=52;
            code%=52;
            if(0<=code&&code<=25) putchar('a'+code);
            if(26<=code&&code<=51) putchar('A'+code-26);
       }
       putchar('\n');
    }
}