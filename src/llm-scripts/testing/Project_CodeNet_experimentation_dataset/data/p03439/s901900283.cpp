#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> p(N); // Male = 1, Female = 2;
    string response;
    auto ask = [&](int pos) {
        cout << pos << endl;
        cin >> response;
        if (response == "Vacant") return -1;
        else if (response == "Male") return 1;
        else return 2;
    };
    p[0] = ask(0);
    if (p[0] == -1) return 0;
    p[N-1] = ask(N-1);
    if (p[N-1] == -1) return 0;
    int left = 0;
    int right = N-1;
    while (right - left > 1){
        int mid = (right + left)/2;
        p[mid] = ask(mid);
        if (p[mid] == -1) return 0;
        if ((right - mid)%2 == 0 && p[mid] != p[right]) left = mid;
        else if ((right - mid)%2 == 1 && p[mid] == p[right]) left = mid;
        else if ((mid - left)%2 == 0 && p[mid] != p[left]) right = mid;
        else if ((mid - left)%2 == 1 && p[mid] == p[left]) right = mid;
    }
    return 0;
}