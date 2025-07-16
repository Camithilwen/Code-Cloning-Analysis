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
    int n,l;
    cin >> n >> l;
    int a[n];
    for(int i=0;i<n;i++){
        a[i] = l+i;
    }
    int c=1;
    if(a[0]<0) c=0;
    int m = abs(a[0]);
    for(int i=0;i<n;i++){
        if(m>abs(a[i])){
            if(a[i]>=0){
                c=1;
            }else{
                c=0;
            }
            m = abs(a[i]);
        }
    }

    int sum =0;
    for(int i=0;i<n;i++){
        sum += a[i];
    }
    if(c){
        cout << sum-m << endl;
    }else{
        cout << sum+m << endl;
    }
}