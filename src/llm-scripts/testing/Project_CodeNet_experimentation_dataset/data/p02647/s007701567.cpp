#include <iostream>
#include <vector>
using namespace std;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main() {
	const int MAXN = 200000;
	int a[MAXN],  b[MAXN]={0};
	int n, k;
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	const int iterations = 41;
	for(int i=1;i<=min(k, iterations);i++) {
		FenwickTree t1(n), t2(n);
		for(int j=0;j<n;j++) {
			b[j] += t1.sum(j, n-1);
			t1.add(min(n-1,j+a[j]), 1);
		}
		for(int j=n-1;j>=0;j--) {
			t2.add(max(0,j-a[j]), 1);
			b[j] += t2.sum(j);
		}
		for(int j=0;j<n;j++) {
			a[j]=b[j];
			b[j]=0;
		}
	}
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}