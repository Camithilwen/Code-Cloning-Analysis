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
    ll l,r;
    cin >> l >> r;
    if(l+1==r){
        cout << ((l%2019)*(r%2019))%2019 << endl;
        return 0;
    }

    if(l==0){
        cout << 0 << endl;
        return 0;
    }

    if(r-l+1>=673){
        cout << 0 << endl;
    }else{
        int m=2018;
        for(int i=l;i<r;i++){
            for(int j=i+1;j<=r;j++){
                m = min(m,((i%2019)*(j%2019))%2019);
            }
        }
       
        cout << m << endl;
    }
}