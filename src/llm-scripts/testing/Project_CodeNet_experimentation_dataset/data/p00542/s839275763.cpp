//q1.cpp

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << #x << " = " << x << endl;


#define mod 1000000007 //1e9+7
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 10000


int main(){
    
    int t[6];
    int ans = 0;
    
    for(int i=0;i<6;i++){
        scanf("%d",&t[i]);
        ans += t[i];
    }
    
    printf("%d\n",ans-min(min(t[0],t[1]),min(t[2],t[3]))-min(t[4],t[5]));
    
    return 0;
}