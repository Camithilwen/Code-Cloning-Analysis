#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main (int argc, char *argv[]) {
    string str;
    int ans = 0;
    int n1, n2, n3;
    cin>>str;

    for (int i = 0; i < str.length(); ++i) {
        n1 = n2 = n3 = 0;
        while (str[i] == 'J') {
            n1++;
            i++;
        }
        while (str[i] == 'O') {
            n2++;
            i++;
        }
        while (str[i] == 'I') {
            n3++;
            i++;
        }
        if(n2 <= n1 && n2 <= n3) ans = max(ans, n2);
        i--;
    }
    cout<<ans<<endl;
    return 0;
}
