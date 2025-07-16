#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    //入力
    int n;
    string s; //左が縦の行数、右が横の列数（念のため、余裕をもって+1）
    int num_e = 0; //西向きの合計人数
    int num_w = 0; //東向きの合計人数
    cin >> n >> s;
    for (int i=0; i<n; i++) {
        if (s[i]=='E') num_e++;
        if (s[i]=='W') num_w++;
    }
    int ans = 300000;
    int change_w = 0; //リーダーの西で向きを変える必要のある人数。西の端から一個ずつ東へズレてカウントしていく。
    int change_e = num_e; //リーダーの東で向きを変える必要のある人数（リーダーの西側に区切り線を置いてる感じ）
    for (int i=0; i<n; i++) {
        if (s[i]=='E') change_e--; //リーダーが'E'の場合、東側から'E'が一人減る
        if (change_e + change_w <= ans) ans = change_e + change_w;
        if (s[i]=='W') change_w++; //リーダーが'W'の場合、西側に'W'が一人増える
    }
    cout << ans << endl;
    return 0;
}