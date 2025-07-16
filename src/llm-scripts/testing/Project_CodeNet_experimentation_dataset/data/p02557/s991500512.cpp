#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<N; i++) cin >> B[i];
    
    reverse(B.begin(), B.end());
    int dup = -1;
    vector<int> dup_idx, avail_idx;
    for(int i=0; i<N; i++) if(A[i] == B[i]){
        dup = A[i];
        dup_idx.push_back(i);
    }
    for(int i=0; i<N; i++) if(A[i] != dup && B[i] != dup) avail_idx.push_back(i);
    
    if(dup_idx.size() > avail_idx.size()){
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    for(int i=0; i<int(dup_idx.size()); i++) swap(B[dup_idx[i]], B[avail_idx[i]]);
    for(int i=0; i<N; i++) cout << B[i] << " \n"[i==N-1];
    return 0;
}
