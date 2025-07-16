#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
using ll = int64_t;
using Graph = vector<vector<int> >;
const ll M = 1000000007;

int main(){
    int n;
    string s;
    cin >> n >> s;

    vector<int> w(n,0);
    vector<int> e(n,0);
    int cntw=0,cnte=0;
    for(int i=0;i<n;i++){
        if(s.at(i)=='W')cntw++;    
        w.at(i)=cntw;
    }

    for(int i=n-1;i>=0;i--){
        if(s.at(i)=='E')cnte++;
        e.at(i)=cnte;
    }

    int ans=n;
    for(int i=0;i<n;i++){
        int tmp=e.at(i)+w.at(i)-1;
        ans=min(ans,tmp);
    }

    cout << ans << endl;
}