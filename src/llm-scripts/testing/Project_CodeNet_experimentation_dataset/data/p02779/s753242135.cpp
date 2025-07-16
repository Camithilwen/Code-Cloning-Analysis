#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A.at(i);
    set<int> B;
    bool flg = true;
    for(int i=0; i<N; i++){
        if(B.find(A.at(i)) == B.end()) B.insert(A.at(i));
        else{
            flg = false;
            break;
        }
    }
    if(flg) cout << "YES" << endl;
    else cout << "NO" << endl;
}