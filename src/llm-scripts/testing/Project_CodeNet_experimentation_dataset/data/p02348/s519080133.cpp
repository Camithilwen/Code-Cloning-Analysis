#include<iostream>
#include<climits>
using namespace std;
// 完成版。

int tree[(1 << 18)];

void Update(int s, int t, int m, int left = 0, int right = (1 << 17), int key = 0){
    if(t < left || right <= s) return;
    if(s <= left && right - 1 <= t){ tree[key] = max(tree[key], m); return; }
    Update(s, t, m, left, (left + right) / 2, 2 * key + 1);
    Update(s, t, m, (left + right) / 2, right, 2 * key + 2);
}

int Find(int i){
    i += (1 << 17) - 1;
    int m = tree[i];
    while(i){
        i = (i - 1) / 2;
        m = max(tree[i], m);
    };
    return m;
}

int main(){
    int i;
    for(i = 0; i < (1 << 18); i++) tree[i] = 0;
    int n, q;
    int x[100000];
    for(i = 0; i < 100000; i++) x[i] = INT_MAX;
    int s, t, value, m;
    m = 1;
    
    cin >> n >> q;
    int query;
    while(q){
        q--;
        cin >> query;
        if(query){
            cin >> i;
            cout << x[Find(i)] << endl;
        }else{
            cin >> s >> t >> value;
            x[m] = value;
            Update(s, t, m);
            m++;
        }
    };
    return 0;
}
