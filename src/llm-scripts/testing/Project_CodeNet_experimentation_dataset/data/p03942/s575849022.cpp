#include<bits/stdc++.h>
#define reg register

const int maxn = 1000005;

int N;

char S[maxn];
char T[maxn];

int main(){
        scanf("%d", &N);
        scanf("%s%s", S+1, T+1);
        int flag = 1;
        for(reg int i = 1; i <= N; i ++)
                if(S[i] != T[i]){ flag = 0; break ; }
        if(flag){ printf("0\n"); return 0; }
        int Min_l = N, Ans = 1;
        std::queue <int> Q;
        for(reg int i = N; i >= 1; i --){
                Min_l = std::min(i, Min_l);
                if(T[i] == T[i-1]) continue ;
                while(Min_l && S[Min_l] != T[i]) Min_l --;
                if(!Min_l){ printf("-1\n"); return 0; }
                while(!Q.empty()){
                        if(Q.front()-Q.size()+1 > i) Q.pop();
                        else break ;
                }
                Q.push(Min_l);
                if(Min_l != i) Ans = std::max(Ans, (int)Q.size() + 1);
        }
        printf("%d\n", Ans);
        return 0;
}