#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> ii;

int n;

string ans, newans;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    cout << "0\n";
    cout.flush();
    cin >> ans;
    if(ans == "Vacant"){
        cout << "0\n";
        cout.flush();
        cin >> ans;
        exit(0);
    }
    int pos = 0;
    for(int i = 17; i >= 0; i--){
        if(pos + (1 << i) < n){
            cout << pos + (1 << i) << "\n";
            cout.flush();
            cin >> newans;
            if(newans == "Vacant"){
                cout << pos + (1 << i) << "\n";
                cout.flush();
                cin >> newans;
                exit(0);
            }
            if(ans == newans)
                pos += (1 << i);
        }
    }
    cout << pos + 1 << "\n";
    cout.flush();
    cin >> newans;
    exit(0);
}
