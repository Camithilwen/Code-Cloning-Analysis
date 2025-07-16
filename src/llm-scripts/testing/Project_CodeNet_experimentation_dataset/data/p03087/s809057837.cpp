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
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    
    vector<int> cnt;
    cnt.push_back(0);
    int tmp=0;
    for(int i=1;i<n;i++){
        if(s.at(i-1)=='A' && s.at(i)=='C') {
            tmp++;
            cnt.push_back(tmp);
        }else{
            cnt.push_back(tmp);
        }
    }

    for(int i=0;i<q;i++){
        int r,l;
        cin >> r >> l;

        int ans=cnt.at(l-1)-cnt.at(r-1);
        cout << ans << endl;
    }
}