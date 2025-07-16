#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> ii;

int n;
string s, temp;
vector<int> vec;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    cout << 0 << "\n";
    cout.flush();
    cin >> s;
    temp = s;
    if(temp == "Vacant")
        exit(0);
    for(int i = 2; i < n; i+=2)
        vec.pb(i);
    int l = 0;
    for(int i = 20; i >= 0; i--){
        if(l + (1 << i) < n){
            cout << l + (1 << i) << "\n";
            cout.flush();
            cin >> s;
            if(s == "Vacant")
                exit(0);
            else{
                if(temp == s)
                    l += (1 << i);
            }
        }
    }
    cout << l + 1 << "\n";
    cout.flush();
    cin >> s;
    exit(0);
}
