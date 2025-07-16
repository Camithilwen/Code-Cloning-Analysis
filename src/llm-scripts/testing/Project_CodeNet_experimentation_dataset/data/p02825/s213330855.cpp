#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;++A)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////
ll N;
ll i, j, k;
char S[1010][1010];

const char mk[10][20][20]={
    {},{},{},{},
    {
        "aacd",
        "bbcd",
        "cdaa",
        "cdbb"
    },
    {
        "aabba",
        "b..ca",
        "b..cb",
        "acc.b",
        "abbaa"
    },
    {
        "aabbaa",
        "c.c.c.",
        "c.c.c.",
        ".c.c.c",
        ".c.c.c",
        "aabbaa"
    },
    {
        ".aabbaa",
        "a.cc.cc",
        "ac..c..",
        "bc..c..",
        "b.cc.cc",
        "ac..c..",
        "ac..c.."
    },
};

void crS(ll a,ll p){
    ll i,j;
    fornum(i,0,a){
        fornum(j,0,a){
            S[p + i][p + j] = mk[a][i][j];
        }
    }
}
int main(){
    scanf("%lld", &N);
    if(N==2){
        printf("-1");
        return 0;
    }
    if(N==3){
        printf("aa.\n");
        printf("..a\n");
        printf("..a\n");
        return 0;
    }
    i = N % 4 + 4;
    crS(i, 0);
    while(i<N){
        crS(4, i);
        i+= 4;
    }
    fornum(i,0,N){
        fornum(j,0,N){
            printf("%c", S[i][j] ? S[i][j] : '.');
        }
        printf("\n");
    }
    
    return 0;
}