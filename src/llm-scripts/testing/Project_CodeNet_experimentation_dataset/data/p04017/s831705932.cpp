#include<bits/stdc++.h>

using namespace std;
using ll = long long;

/***********debug tools***********/
template<class T> inline ostream& operator<<(ostream& os,vector<T> arr) {os << "["; for(int i = 0; i < (int)arr.size(); i++)os << arr[i] << (i == (int)arr.size() - 1 ? "]" : ",");os << endl;return os;}
template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A,B>& p){os << "{" << p.first << "," << p.second << "}";return os; }
#define prvec(v) cerr<<#v<<": [";for(int __i = 0;__i < (int)(v).size(); __i++)cerr<<((v)[__i])<<(__i+1==(int)(v).size()?"]\n":",");
#define print(x) cerr<<#x<<": "<<(x)<<endl
/*********************************/

const int D = 30;
const int MAX_N = 100000;

int n, l;
vector<int> x;
vector<vector<int>> tor, tol;



void ftor() {
    for(int i = 0; i < n; i++) {

        int L = i + 1, R = n; //ooooxxx
        while(R - L > 1) {
            int mid = (L + R) / 2;
            (x[mid] - x[i] <= l ? L : R) = mid;
        }
        tor[0][i] = L;
    }
    tor[0][n - 1] = n - 1;

    for(int i = 0; i < D - 1; i++) {
        for(int j = 0; j < n; j++) {
            tor[i + 1][j] = tor[i][tor[i][j]];
        }
    }

}

void ftol() {
    for(int i = 1; i < n; i++) {
        int L = -1, R = i - 1;//xxxxxoooo
        while(R - L > 1) {
            int mid = (L + R) / 2;
            (x[i] - x[mid] <= l ? R : L) = mid;
        }
        tol[0][i] = R;
    }
    tol[0][0] = 0;
    for(int i = 0; i < D - 1; i++) {
        for(int j = 0; j < n; j++) {
            tol[i + 1][j] = tol[i][tol[i][j]];
        }
    }

}


int main()
{
    cin >> n;
    x.resize(n), tor.resize(D, vector<int>(n));
    tol = tor;
    for(int i = 0; i < n; i++)cin >> x[i];
    cin >> l;
    ftor();
    ftol();

    int Q; cin >> Q;
    while(Q--) {
        int a, b;
        cin >> a >> b;
        a--,b--;
        if(a > b) {

            int l = 0, r = 2 * n;//xxxxxxoooo
            while(r - l > 1) {
                int mid = (l + r) / 2;
                int pos = a;
                for(int i = 0; i < D; i++) {
                    if(mid & (1<<i))pos = tol[i][pos];
                }
                (pos <= b ? r : l) = mid;
            }
            cout << r << endl;      
            

        } else {
            int l = 0, r = 2 * n;//xxxxxxoooo
            while(r - l > 1) {
                int mid = (l + r) / 2;
                int pos = a;
                for(int i = 0; i < D; i++) {
                    if(mid & (1<<i))pos = tor[i][pos];
                }
                (pos >= b ? r : l) = mid;
            }
            cout << r << endl;
        }

    }

}
