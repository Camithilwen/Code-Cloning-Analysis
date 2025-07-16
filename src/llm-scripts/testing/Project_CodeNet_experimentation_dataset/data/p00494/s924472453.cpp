#include <bits/stdc++.h>
using namespace std;
typedef pair<char,int> P;
char S[1000001];
vector<P> V;
int main() {
    scanf("%s",S);
    char ch=S[0];
    int cnt=0;
    for(int i=0;S[i]!='\0';i++) {
        if(ch==S[i]) {
            cnt++;
        }else {
            V.push_back(P(ch,cnt));
            cnt=1;
            ch=S[i];  
        }
    }
    V.push_back(P(ch,cnt));
    int ans=0;
    for(int i=0;i+2<V.size();i++) {
        if(V[i].first!='J'||V[i+1].first!='O'||V[i+2].first!='I') continue;
        if(V[i].second>=V[i+1].second&&V[i+2].second>=V[i+1].second) {
            ans=max(ans,V[i+1].second);
        }
    }
    printf("%d\n",ans);
}