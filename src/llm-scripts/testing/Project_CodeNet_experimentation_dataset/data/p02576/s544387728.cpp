#include<iostream>
using namespace std;
int main()
{
    // 整数の入力
    int N, X, T;
    cin >> N >> X >> T;
    // スペース区切りの整数の入力
    int x = N / X * T;
    if ( N % X > 0 ){
      x += T;
    }
    cout << x << endl;
    
}