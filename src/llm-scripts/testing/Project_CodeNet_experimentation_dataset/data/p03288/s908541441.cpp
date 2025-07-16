#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long int ll;
typedef pair<int,int> P;
const int INF = 1e9+7;

int main(){
    int r;
    cin >> r;
    if(r<1200){
        cout << "ABC";
    }else if(1200<=r&&r<2800){
        cout << "ARC";
    }else{
        cout << "AGC";
    }
}