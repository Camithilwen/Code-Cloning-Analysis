#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
const long long inf = 1000000001; // const 書き換え禁止
const double PI = 3.14159265358979323846; //M_PI はライブラリ

int main(void){
    int k,x;
    cin >> k >> x;
    int a = k-1;
    for(int i=x-a;i<=x+k-1;i++){
        cout << i;
        cout << " ";
    }
    cout << endl;
}