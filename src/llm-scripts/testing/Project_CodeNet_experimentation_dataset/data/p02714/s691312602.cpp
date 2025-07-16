//
//  main.cpp
//  D
//
//  Created by 曾憲揚 on 2020/8/21.
//  Copyright © 2020 曾憲揚. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e3+5;

int main(int argc, const char * argv[]) {
    int n; cin>>n;
    string s; cin>>s;
    
    int r=0, g=0, b=0;
    for(int i=0; i<n; i++){
        if(s[i]=='R') r++;
        else if(s[i]=='G') g++;
        else if(s[i]=='B') b++;
    }
    long long ans = 1LL*r*g*b;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(s[i] == s[j]) continue;
            int k = j+(j-i);
            if(k>=n) break;
            if(s[k] != s[i] && s[k] != s[j]) ans--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
