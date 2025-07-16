#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
#include <math.h>
#include <utility>
#include <stack>
#include <string.h>
using namespace std;
typedef pair<int,int> P;
const int INF = ~(1<<31) / 2;

int c[100][100];
int t[100][100];
int n,m,k;

int main(){
    while(1){
        scanf("%d %d",&n,&m);
        if(n==0) break;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                c[i][j] = 1000000;
                t[i][j] = 1000000;
            }
        }
        for(int i=0;i<n;i++){
            int a,b,co,ti;
            scanf("%d %d %d %d",&a,&b,&co,&ti);
            a--;b--;
            c[a][b] = co;
            c[b][a] = co;
            t[a][b] = ti;
            t[b][a] = ti;
        }

        for(int k=0;k<m;k++){
            for(int i=0;i<m;i++){
                for(int j=0;j<m;j++){
                    c[i][j] = min(c[i][j],c[i][k]+c[k][j]);
                    t[i][j] = min(t[i][j],t[i][k]+t[k][j]);
                }
            }
        }

        scanf("%d",&k);
        for(int i=0;i<k;i++){
            int p,q,r;
            scanf("%d %d %d",&p,&q,&r);
            p--;q--;
            if(r)printf("%d\n",t[p][q]);
            else printf("%d\n",c[p][q]);
        }
    }
    return 0;
}