#include <iostream>
#include <vector>
using namespace std;

int InsertionSort(vector<int> &A, int g){
    int N = A.size();
    int cnt = 0;
    
    for(int i = g; i < N; ++i){
        int v = A[i];
        int j = i - g;
        while(j >= 0 && A[j] > v){
            A[j + g] = A[j];
            j = j - g;
            ++cnt;
        }
        A[j + g] = v;
    }
    
    return cnt;
}

int main(void){
    int cnt = 0;
    int N;
    cin >> N;
    vector<int> A(N, 0);
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    
    
    vector<int> G;
    int g = 1;
    while(g <= N){
        G.push_back(g);
        g = 3 * g + 1;
    }
    int m = G.size();
    cout << m << endl;
    for(int i = m - 1; i >= 0; --i){
        cout << G[i];
        if(i != 0)
            cout << " ";
    }
    cout << endl;
    
    for(int i = m - 1; i >= 0; --i){
        cnt += InsertionSort(A, G[i]);
    }
    cout << cnt << endl;
    
    for(int i = 0; i < N; ++i){
        cout << A[i];
        if(i != N - 1)
            cout << endl;
    }
    
    return 0;
}