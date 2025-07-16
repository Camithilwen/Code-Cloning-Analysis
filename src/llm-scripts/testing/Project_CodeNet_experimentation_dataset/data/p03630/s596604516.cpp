#include<iostream>
#include<iomanip>
#include<cassert>
#include<stdexcept>
#include<utility>
#include<functional>
#include<numeric>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<array>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<complex>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<bitset>
#include<memory>
using namespace std;
using ll=long long;

int main(){
    int h,w;
    cin>>h>>w;
    vector<string> s(h);
    for(int i=0;i<h;i++) cin>>s[i];

    int res = max(h,w);
    vector<vector<int>> b(h-1,vector<int>(w-1));
    auto judge=[&](int i,int j){
        return (int)(s[i][j]=='#');
    };
    for(int i=0;i+1<h;i++){
        for(int j=0;j+1<w;j++){
            int cnt = judge(i,j) + judge(i+1,j) +judge(i,j+1) + judge(i+1,j+1);
            b[i][j] = (cnt%2==0);
        }  
    }

    vector<vector<int>> sum(h,vector<int>(w));
    for(int i=0;i<h-1;i++){
        for(int j=0;j<w-1;j++){
            if(b[i][j]) sum[i+1][j] = sum[i][j]+1;
        }
    }
    
    for(int i=0;i<h-1;i++){
        int x = i+1;
        stack<pair<int,int>> lh;
        lh.push({-1,0});
        for(int y=0;y<w;y++){
            while(sum[x][y]<lh.top().second){
                auto tmp = lh.top(); lh.pop();
                int height = tmp.second;
                int width = y-lh.top().first;
                res = max(res,width*(height+1));
            }
            lh.push({y,sum[x][y]});
        }
    }
    cout<<res<<endl;
    
    return 0;
}
