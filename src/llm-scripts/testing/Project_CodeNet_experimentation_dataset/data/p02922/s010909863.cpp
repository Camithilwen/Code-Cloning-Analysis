#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#define _GLIBCXX_DEBUG
using namespace std;
const long long INF = 1LL << 60;
int main() {
    int A,B;
    cin >> A >> B;
    int ans;
    if( B==1){
        ans =0;
    }
    else{
        for(int i=1;i>0;i++){
            if((A-1)*(i-1)+A >= B){
                ans = i;
                break;
            }
        }
    }
    cout << ans << endl;
}