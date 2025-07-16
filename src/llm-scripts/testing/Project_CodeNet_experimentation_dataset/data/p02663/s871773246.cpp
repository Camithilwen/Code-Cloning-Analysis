// https://atcoder.jp/contests/nomura2020/tasks/nomura2020_a

#include<iostream>
#include<vector>//可変長配列
#include<algorithm>//sort,二分探索,など
#include<map>//map(辞書)

using namespace std;

int main(void){
    int h1, m1, h2, m2, k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    int wake = h1 * 60 + m1;
    int sleep = h2 * 60 + m2;
    int diff = sleep - wake - k;
    cout << diff << endl;
    return 0;
}