#include <iostream>
#include <vector>
using namespace std;

#define SENTINEL 2000000000

long long merge(vector<int>& array, int left, int mid, int right) {
    long long cnt = 0;          // 転倒数を数える
    // 分割した配列LとRを生成
    int n1 = mid - left;        // Lの大きさ
    int n2 = right - mid;       // Rの大きさ
    vector<int> L(n1 + 1);
    vector<int> R(n2 + 1);
    for (int i = 0; i < n1; ++i) {
        L[i] = array[left + i];
    }
    for (int i = 0; i < n2; ++i) {
        R[i] = array[mid + i];
    }
    L[n1] = SENTINEL;
    R[n2] = SENTINEL;

    // LとRを比べて，もとの配列へソート
    int i = 0, j = 0;
    for (int k = left; k < right; ++k) {
        if (L[i] <= R[j]) {
            array[k] = L[i++];
        } else {
            array[k] = R[j++];
            cnt += n1 - i;
        }
    }

    return cnt;
}

long long mergeSort(vector<int>& array, int left, int right) {
    int mid;
    long long cnt1, cnt2, cnt3;
    if (left + 1 < right) {
        mid = (left + right) / 2;
        cnt1 = mergeSort(array, left, mid);
        cnt2 = mergeSort(array, mid, right);
        cnt3 = merge(array, left, mid, right);
        return cnt1 + cnt2 + cnt3;
    } else {
        return 0;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> array(n);
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }
    
    long long ans = mergeSort(array, 0, n);

    cout << ans << endl;

    return 0;
}
