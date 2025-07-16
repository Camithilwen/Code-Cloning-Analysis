#include <iostream>
#include <vector>

using namespace std;

const int INF = 2147483647;

struct SegmentTree {
    int n;
    vector<int> heap;
    
    SegmentTree(int n): n(n) {
        heap.assign(4 * n, INF);
    }
    
    void update(int nodeId, int l, int r, int ql, int qr, int v) {
        if (qr < l || ql > r) {
            return;
        }
        else if (ql <= l && r <= qr) {
            heap[nodeId] = v;
        }
        else {
            pushdown(nodeId);
            int m = l + (r - l)/2;
            update(nodeId * 2, l, m, ql, qr, v);
            update(nodeId * 2 + 1, m + 1, r, ql, qr, v);
        }
    }
    
    int query(int nodeId, int l, int r, int q) {
        if (q < l || q > r) {
            return -1;
        }
        else if (heap[nodeId] != -1) {
            return heap[nodeId];
        }
        else {
            int m = l + (r - l)/2;
            return max(query(nodeId * 2, l, m, q), query(nodeId * 2 + 1, m + 1, r, q));
        }
    }
    
    void pushdown(int nodeId) {
        //cout << "push: " << nodeId << endl;
        if (heap[nodeId] != -1) {
            heap[nodeId * 2] = heap[nodeId];
            heap[nodeId * 2 + 1] = heap[nodeId];
            heap[nodeId] = -1;   
        }
    }
    
};

int main() {
    int n, q;
    cin >> n >> q;
    SegmentTree st(n);
    for (int i = 0; i < q; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 0) {
            int ql, qr, v;
            cin >> ql >> qr >> v;
            st.update(1, 0, n -1, ql, qr, v);
//            for (int i = 0; i < 4 * n; i++) {
//                cout << i << ":" << st.heap[i] << endl; 
//            }
        }
        else {
            int pos;
            cin >> pos;
            cout << st.query(1, 0, n-1, pos) << endl;
        }
    }
    
    return 0;
}