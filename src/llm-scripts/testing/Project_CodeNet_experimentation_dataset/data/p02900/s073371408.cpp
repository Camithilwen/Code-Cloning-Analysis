#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
#define MOD 1000000007
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;

int main() {
    ll A, B;
    cin >> A >> B;
    vector<ll> num_A;
    vector<ll> num_B;
    vector<ll> num;
    num_A.push_back(1);
    num_B.push_back(1);
    for(int i = 2; i <= sqrt(A); i++){
        if(A % i == 0){
            while(A % i == 0){
                A = A / i;
            }
            num_A.push_back(i);
        }
    }
    num_A.push_back(A);
    sort(num_A.begin(),num_A.end());
    num_A.erase(unique(num_A.begin(), num_A.end()), num_A.end());

    for(int i = 2; i <= sqrt(B); i++){
        if(B % i == 0){
            while(B % i == 0){
                B = B / i;
            }
            num_B.push_back(i);
        }
    }
    num_B.push_back(B);
    sort(num_B.begin(),num_B.end());
    num_B.erase(unique(num_B.begin(), num_B.end()), num_B.end());

    for(int i = 0; i < num_A.size(); i++){
        for(int j = 0; j < num_B.size(); j++){
            if(num_A[i] == num_B[j]){
                num.push_back(num_A[i]);
            }
        }
    }

    cout << num.size() << endl; 
}