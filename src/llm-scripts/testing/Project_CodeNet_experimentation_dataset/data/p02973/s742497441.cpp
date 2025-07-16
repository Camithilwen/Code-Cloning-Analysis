#include <bits/stdc++.h>
using namespace std;

// 参考資料：https://hiramekun.hatenablog.com/entry/2019/07/21/082628

#define N 100000
#define INF ((1<<31)-1)

multiset<int> setMaxNum;       // 色ごとに仕分けされた集合の最大値を格納

int main() {
    // 入力
    int n;
    vector<int> a;
    cin >> n;
    for (int i = 0; i < n; i++){
        int aTmp;
        cin >> aTmp;
        a.push_back(aTmp);
    }
    
    // 
    for (int i = 0; i < n; i++){
        auto itr = setMaxNum.lower_bound(a[i]);
        if (itr != setMaxNum.begin()){          // 入力値 a[i] より小さい setMaxNum がある場合、その集合と同じ色で塗れる
            setMaxNum.erase(--itr);             // 同じ色で塗られてる集合の最大値が変わるため、元の最大値を削除する
        }
        setMaxNum.insert(a[i]);
    }

    cout << setMaxNum.size() << endl;

    return 0;
}
