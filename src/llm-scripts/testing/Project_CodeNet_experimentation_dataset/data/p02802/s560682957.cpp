#include <bits/stdc++.h>
using namespace std;
void printVector(const vector<int>& vec) {
    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;
}

int main() {
    int N,M;
    cin >> N >> M;
    vector<int> p(M);
    vector<string> S(M);
    for(int i=0;i<M;i++) {
        cin >> p.at(i) >> S.at(i);
    }
    vector<vector<int>> submits(N,vector<int>(2,0));
    for(int i=0;i<M;i++) {
        if(submits.at(p.at(i)-1).at(0) != 0) {
            continue;
        }
        if(S.at(i) == "WA") {
            submits.at(p.at(i)-1).at(1)++;
        }else{
            submits.at(p.at(i)-1).at(0)++;
        }
    }
    int ac = 0;
    int pena = 0;

    for(int i=0;i<N;i++) {
        if (submits.at(i).at(0) == 0) {
            continue;
        }
        ac += submits.at(i).at(0);
        pena += submits.at(i).at(1);
    }
    cout << ac << " " << pena << endl;
    /*
    cout << "ans" << endl;
    for(int i=0;i<N;i++) {
        cout << submits.at(i).at(0) <<" "<< submits.at(i).at(1) << endl;
    }
    */
}