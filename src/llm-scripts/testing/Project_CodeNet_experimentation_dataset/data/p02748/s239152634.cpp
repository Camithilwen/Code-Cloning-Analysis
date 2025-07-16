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
typedef long long ll;
int main() {
    int A,B,M;
    cin >> A >> B >> M;
    //
    vector<int> a(A);
    for(int i=0;i<A;i++){
        cin >> a[i];
    }
    //
    vector<int> b(B);
    for(int i=0;i<B;i++){
        cin >> b[i];
    }
    //
    vector<int> x(M);
    vector<int> y(M);
    vector<int> c(M);
    for(int i=0;i<M;i++){
        cin >> x[i] >> y[i] >> c[i] ;
    }
    //
    ll price;
    ll min_price;
    for(int i=0;i<M;i++){
        price = a[x[i]-1] + b[y[i]-1] - c[i];
        if(i==0){
            min_price = price;
        }
        else if(min_price > price){
            min_price = price;
        }
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    price = a[0] + b[0];
    if(min_price > price){
        min_price = price;
    }
    cout << min_price << endl;
}