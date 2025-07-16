// Author :
// Date :
// Problem:
// Solution:
// Comment:

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <cstring>

#define pp push
#define pb push_back
#define mp make_pair
#define xx first
#define yy second

using namespace std;

void play(int n,int mm){
    int ans[105] = {0};
    int cur = -1;
    int day = 0;
    int q;
    
    for(int i = 0 ; i < n ; i ++){
        int m;
        
        cin >> m;
        for(int i = 0 ; i < m ; i++){
            cin >> q;
            ans[q]++;
        }
    }
    
    for(int i = 0 ; i < 103 ; i++){
        if(ans[i] > cur && ans[i] >=mm){
            cur = ans[i];
            day = i;
        }
    }
    
    cout << day << endl;
}

main(){
    int nn,mm;
    
    while(cin >> nn >> mm){
        if(nn == 0) break;
        play(nn,mm);
    }
    #ifdef GEREL
        for(;;);
    #endif

    return 0;
}