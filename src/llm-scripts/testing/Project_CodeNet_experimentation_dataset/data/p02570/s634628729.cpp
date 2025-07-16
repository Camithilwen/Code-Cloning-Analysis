#include <iostream>
using namespace std;
 
int main() {
    //入力を受け取る
    int D, T, S;
    cin >> D >> T >> S;
 
    //高橋君の移動時間を計算する
    int dist = S * T;
 
    //Dとdistの大小関係に応じて出力をする
    if (dist >= D) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}