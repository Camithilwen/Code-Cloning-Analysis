#include<bits/stdc++.h>
using namespace std;

int main(){
    int64_t N;
    cin >> N;
    cout << (N / 1 * 1 * (N / 1 + 1) - N / 3 * 3 * (N / 3 + 1) - N / 5 * 5 * (N / 5 + 1) + N / 15 * 15 * (N / 15 + 1)) / 2 << endl;
}