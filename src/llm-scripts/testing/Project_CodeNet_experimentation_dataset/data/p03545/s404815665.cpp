#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
typedef long long ll;

vector<int> vec(4);

string judge(int su, int num, string op) {
    if (num == 4) {
        if (su == 7 - vec[0]) {
            return op;
        }
        else return "";
    }
    if (judge(su + vec[num], num + 1, op + "+") != "") {
        return judge(su + vec[num], num + 1, op + "+");
    }
    if (judge(su - vec[num], num + 1, op + "-") != "") {
        return judge(su - vec[num], num + 1, op + "-");
    }
    return "";
}

int main() {
    char A,B,C,D; cin >> A >> B >> C >> D;
    vec[0] = A - '0', vec[1] = B - '0', vec[2] = C - '0', vec[3] = D - '0';
    string op = "";

    string a = judge(0, 1, op);
    cout << vec[0] << a[0] << vec[1] << a[1] << vec[2] << a[2] << vec[3] << "=7" << endl;
}