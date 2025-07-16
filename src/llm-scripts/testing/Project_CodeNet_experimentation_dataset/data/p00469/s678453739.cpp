#include<cstdio>
#include<algorithm>
#include<queue>
#include<string>
#include<cstring>
#include<cstdlib>
#include<sstream>
#include<set>
using namespace std;
class P{
    public:
    int num;
    int cnt;
    bool used[10];
    P(){}
    P(int num,int cnt,bool a[10]):num(num),cnt(cnt){
        for(int i = 0; i < 10; i++){
            used[i] = a[i];
        }
    }
};
int bond(int x,int y){
    stringstream ss1;
    ss1 << x;
    stringstream ss2;
    ss2 << y;
    string ans = ss1.str() + ss2.str();
    stringstream Ans;
    Ans << ans;
    int res;
    Ans >> res;
    return res;
}
int main(){
    int n;
    int m;
    while(scanf("%d%d",&n,&m),(n|m)){
        int card[10];
        set<int> S;
        queue<P> Q;
        for(short i = 0; i < n; i++){
            bool x[10]={0};
            x[i] = 1;
            scanf("%d",&card[i]);
            Q.push(P(card[i],1,x));
        }
        short ans = 0;
        while( Q.size() ){
            P p = Q.front();Q.pop();
            if(p.cnt == m){
                if(S.find(p.num) == S.end())ans++,S.insert(p.num);
            }
            else{
                for(int i = 0; i < n; i++){
                    if(p.used[i] == 0){
                        p.used[i] = 1;
                        Q.push(P(bond(p.num,card[i]),p.cnt+1,p.used));
                        p.used[i] = 0;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}