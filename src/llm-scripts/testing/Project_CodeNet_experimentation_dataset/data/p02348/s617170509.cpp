#include <iostream>
#include<iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <queue>
#include <tuple>
#include <map>
#include <list>
#include <string>
#include <numeric>
#include <utility>
#include <cfloat>
#include <set>
 
using namespace std;
 
int sqrtN = 512;
struct SqrtDecomposition{
    int N, K;
    vector <long long> data;
    vector <long long> bucketUpdatedLazy;
     
    SqrtDecomposition(int n){
        N = n;
        K = (N + sqrtN - 1) / sqrtN;
        data.assign(N, ((long long) 1 << 31) - 1);
        bucketUpdatedLazy.assign(K, -1);
    }
 
    void propagateLazy(int k){
        if(bucketUpdatedLazy[k] < 0){
            return;
        }
        for(int i = 0; i < sqrtN; i++){
            data[k * sqrtN + i] = bucketUpdatedLazy[k];
        }
        bucketUpdatedLazy[k] = -1;
    }

    long long get(int x){
        propagateLazy(x / sqrtN);
        return data[x];
    }
 
    void update(int x, int y, int a){
        if(y - x < sqrtN){
            propagateLazy(x / sqrtN);
            propagateLazy((y - 1) / sqrtN);
            for(int i = x; i < y; i++){
                data[i] = a;
            }
            return;
        }
        for(int i = x / sqrtN + 1; i < y / sqrtN; i++){
            bucketUpdatedLazy[i] = a;
            //if(bucketUpdatedLazy[i] < 0 && bucketUpdatedLazy[i] != -1){
            //    cerr << "Warning" << endl;
            //}
        }

        propagateLazy(x / sqrtN);
        for(int i = x; i < (x / sqrtN + 1) * sqrtN; i++){
            data[i] = a;
        }
        propagateLazy((y - 1)/ sqrtN);
        for(int i = y / sqrtN * sqrtN; i < y; i++){
            data[i] = a;
        }
    }
     
};

 
int main(){
    int n;
    int q;
    cin >> n >> q;
    SqrtDecomposition sq(n);
    for(int i = 0; i < q; i++){
        int com;
        int s;
        int t;
        int x;
        cin >> com;
        if(com == 0){
            cin >> s >> t >> x;
            sq.update(s, t + 1, x);
        } else {
            cin >> x;
            cout << sq.get(x) << endl;
        }
    }
    return 0;
}
