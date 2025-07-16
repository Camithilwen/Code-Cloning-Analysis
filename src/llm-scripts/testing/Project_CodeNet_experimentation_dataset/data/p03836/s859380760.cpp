#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 1e5 + 7, M = 1e7, OO = 0x3f3f3f3f;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); cin.sync_with_stdio(0);
int main()
{
int sx,sy,tx,ty,i,x,y;
scanf("%d %d %d %d",&sx,&sy,&tx,&ty);
x=tx-sx;
y=ty-sy;
for(i=0;i<x;++i){
    printf("R");
}
for(i=0;i<y;++i){
    printf("U");
}
for(i=0;i<x;++i){
    printf("L");
}
for(i=0;i<y;++i){
    printf("D");
}
printf("D");
for(i=0;i<x+1;++i){
    printf("R");
}
for(i=0;i<y+1;++i){
    printf("U");
}
printf("L");
printf("U");
for(i=0;i<x+1;++i){
    printf("L");
}
for(i=0;i<y+1;++i){
    printf("D");
}
printf("R");





    return 0;
}
