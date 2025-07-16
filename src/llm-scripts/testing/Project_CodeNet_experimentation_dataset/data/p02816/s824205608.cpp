#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;

template <class T>
void debug(T& v)
{
    for(auto& x: v) cout << x << " ";
    cout << endl;
}

// KMP
template <class T>
std::vector<int> KMP(T& S)
{
    std::vector<int> A(S.size()+1);
    A[0] = -1;
    int j = -1;

    for(int i=0; i<S.size(); i++){
        while(j > -1 && S[j] != S[i]) j = A[j];
        j++;
        A[i+1] = j;
    }

    return A;
}

// detect T from S
template <class Type>
std::vector<int> matchedIndex(Type& S, Type& T)
{
    std::vector<int> ret;
    std::vector<int> A = KMP(T);

    for(int m = 0, i = 0; m + T.size() <= S.size();){
        while(m+i < S.size() && i < T.size() && S[m+i] == T[i]) i++;
        if(i == T.size()) ret.push_back(m);
        m += std::max(i - A[i], 1);
        i = std::max(A[i], 0);
    }

    return ret;
}

int main()
{
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    for(auto& x: a) cin >> x;
    for(auto& x: b) cin >> x;
    a.push_back(a[0]);
    b.push_back(b[0]);
    
    vector<int> c(N), d(2*N);
    for(int i=0; i<N; i++){
        c[i] = a[i] ^ a[i+1];
        d[i] = b[i] ^ b[i+1];
        d[N+i] = d[i];
    }
    d.pop_back();

    vector<int> index = matchedIndex(d, c);
    for(auto& k: index){
        k = (N-k)%N;
    }
    sort(index.begin(), index.end());

    for(auto& k: index){
        cout << k << " " << (a[k] ^ b[0]) << endl;
    }
}