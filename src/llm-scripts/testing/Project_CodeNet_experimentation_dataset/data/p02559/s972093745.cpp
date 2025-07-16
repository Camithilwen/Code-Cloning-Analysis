#include <iostream>
#include <atcoder/fenwicktree>

using namespace std;
using namespace atcoder;

int main() {
    int N,Q;
    cin >> N >> Q;
    fenwick_tree<long long int> fw(N);
    for(int i=0;i<N;i++) {
        int a;
        cin >> a;
        fw.add(i, a);
    }

    for(int i=0;i<Q;i++) {
        int t,c,d;
        cin >> t >> c >> d;
        if(t==0){
            fw.add(c, d);
        }else{
            cout << fw.sum(c, d) << endl;
        }
    }
}